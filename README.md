# Tris Possibilities

Il programma genera una truttura ad albero di **Nodi** che contengono le matrici con tutte le possibili alternative della griglia del tris. Ogni nodo è cosi strutturato:

``` c++
struct Node{
  // matrice tris
  int mat[3][3];
  // 1 o 0 -> X o O
  int turn;
  // numero di mosse effettuate
  int tot;
  // puntatore al nodo precedente
  Node* back;
  // puntatori ai 9 nodi sucessivi
  Node* next[9];
};
```

``` c++
int mat[3][3];
```
La matrice del tris si riudce 9 caselle (3x3). **Integer**, ogni cella può assumere 0(vuota), 1(X) o 2(O).
<table>
  <tr>
    <td>
      <table>
        <tr><td>2</td><td>1</td><td>2</td></tr>
        <tr><td>0</td><td>1</td><td>0</td></tr>
        <tr><td>1</td><td>2</td><td>0</td></tr>
      </table>
    </td>
    <td>
      <table>
        <tr><td>O</td><td>X</td><td>O</td></tr>
        <tr><td> </td><td>X</td><td> </td></tr>
        <tr><td>X</td><td>O</td><td> </td></tr>
      </table>
    </td>
  </tr>
  <tr>
    <td>
      <table>
        <tr><td>1</td><td>2</td><td>1</td></tr>
        <tr><td>2</td><td>2</td><td>1</td></tr>
        <tr><td>1</td><td>1</td><td>2</td></tr>
      </table>
    </td>
    <td>
      <table>
        <tr><td>X</td><td>O</td><td>X</td></tr>
        <tr><td>O</td><td>O</td><td>X</td></tr>
        <tr><td>X</td><td>X</td><td>O</td></tr>
      </table>
    </td>
  </tr>
</table>
