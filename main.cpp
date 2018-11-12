#include <stdio.h>
#include <stdlib.h>

struct Node{
	int mat[3][3];
	int turn;
	int tot;
	Node* back;
	Node* next[9];	
};

void show_mat(int mat[3][3]){
	for (int y=0; y<3; y++){
		for (int x=0; x<3; x++){
			printf("%d", mat[x][y]);
		}
		printf("\n");
	}
}

bool control(int mat[3][3]){
	for (int i=0; i<3; i++){
		if (mat[i][i] == 0)
			continue;
		bool o=1, v=1;
		for (int j=0; j<2; j++){
			if (mat[i][j] != mat[i][j+1])
				v = false;
			if (mat[j][i] != mat[j+1][i])
				o = false;
		}
		if (o || v)
			return true;
	}
	if (mat[1][1] == 0)
		return false;
	if ((mat[0][0] == mat[1][1])
	&& (mat[1][1] == mat[2][2]))
		return true;
	if ((mat[0][2] == mat[1][1])
	&& (mat[1][1] == mat[2][0]))
		return true;
	return false;
}

void show_winners(Node* node){
	printf("\n");
	if (node == NULL) return;
	if (control(node->mat)){
		show_mat(node->mat);
		getchar();
	}else
		for (int i=0;i<9; i++)
			show_winners(node->next[i]);
	
}

void show_node(Node* node){
	if (node == NULL) return;
	show_mat(node->mat);
	printf("%d\n", node->turn);
	printf("%d\n", node->tot);
	if (control(node->mat))
		printf("WINNER");
	printf("\n\n");
	for (int i=0;i<9; i++)
		show_node(node->next[i]);
}

bool empty(int mat[3][3], int x, int y){
	return (mat[x][y] == 0);
}

void asd(Node* node){
	if (node->tot > 8)
		return;
	if (control(node->mat))
		return;
	int i = 0;
	for (int y=0; y<3; y++){
		for (int x=0; x<3; x++){
			if (empty(node->mat, x, y)){
				Node* n = new Node();
				n->turn = node->turn%2+1;
				n->tot = node->tot+1;
				// copy mat
				for (int y=0; y<3; y++){
					for (int x=0; x<3; x++){
						n->mat[x][y] = node->mat[x][y];
					}
				}
				n->mat[x][y] = n->turn;
				node->next[i] = n;
				n->back = node;
				asd(n);
			}
			i++;
		}
	}
}

void write_node(FILE *f, Node* node){
	if (node == NULL) return;
	for (int y=0; y<3; y++){
		for (int x=0; x<3; x++){
			fprintf(f, "%d", node->mat[x][y]);
		}
		fprintf(f, " ");
	}
	if (control(node->mat))
		fprintf(f, "Winner\n");
	else
		fprintf(f, "\n");
	for (int i=0; i<9; i++){
		write_node(f, node->next[i]);
	}
}

void write(Node* head){
	FILE *f = fopen("file.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	write_node(f, head);	
	fclose(f);
}

int main(){
	Node* head = new Node();

	head->turn = 2;
	head->tot = 0;
	asd(head);
	write(head);	
}
