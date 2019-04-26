//
//// DFS
//#define inf 9999999999
//class CGrafo {
//	typedef unsigned short uint;
//	struct nodo {
//		short id;
//		uint d;
//		uint f;
//		nodo* padre;
//		bool visitado;
//		nodo(short id)
//			: id(id), d(inf), f(inf), padre(NULL), visitado(false) {}
//		void inicializa() {
//			this->d = inf;
//			this->f = inf;
//			this->padre = NULL;
//			this->visitado = false;
//		}
//		void mostrar() {
//			cout << "Nodo " << this->id << endl;
//			if (this->padre) cout << " - Padre    : " << this->padre->id << endl;
//			cout << " - d: " << this->d << endl;
//			cout << " - f: " << this->f << endl;
//		}
//	};
//	vector<nodo*>* V;
//	list<nodo*>* E;
//	uint tiempo;
//public:
//	CGrafo(int n) {
//		this->V = new vector<nodo*>;
//		for (short i = 0; i < n; i++)
//			this->V->push_back(new nodo(i));
//		this->E = new list<nodo*>[n];
//	}
//	~CGrafo() {
//		for (short i = 0; i < this->V->size(); i++)
//			delete this->V->at(i);
//		delete this->V;
//		delete this->E;
//	}
//	void arista(int u, int v) {
//		this->E[u].push_back(V->at(v));
//	}
//	void mostrar() {
//		for (auto u : *this->V) {
//			cout << u->id << ": ";
//			for (auto v : this->E[u->id])
//				cout << v->id << ", ";
//			cout << endl;
//		}
//	}
//	void DFS() {
//		this->inicializar();
//		this->tiempo = 0;
//		for (nodo* u : *this->V)
//			if (u->visitado == false)
//				this->DFS_visit(u);
//	}
//	void mostrarResultado() {
//		for (nodo* u : *this->V)
//			u->mostrar();
//	}
//private:
//	void DFS_visit(nodo* u) {
//		u->visitado = true;
//		this->tiempo++;
//		u->d = this->tiempo;
//		for (nodo* v : this->E[u->id])
//			if (v->visitado == false)
//				this->DFS_visit(v);
//		u->f = ++this->tiempo;
//	}
//	void inicializar() {
//		for (nodo* u : *this->V)
//			u->inicializa();
//	}
//	list<nodo*>* ady(nodo* u) {
//		return &this->E[u->id];
//	}
//
//};
//
//int main() {
//	CGrafo G = CGrafo(5);
//	G.arista(0, 3);
//	G.arista(0, 2);
//	G.arista(1, 0);
//	G.arista(2, 3);
//	G.arista(3, 1);
//	G.arista(4, 0);
//	G.DFS();
//	G.mostrarResultado();
//	system("pause>0");
//	return 0;
//}
//
//// BFS
//
//#define INF 200000000
//
//void bfs(int root) // root: Vértice raíz
//{
//	queue<int> q; q.push(root); // Encolar el vértice raíz
//	dist[root] = 0;  // La distancia al vértice raíz es 0 
//	color[root] = 1; // Marcar el vértice como visitado
//	while (!q.empty()) // Mientras existan vértices encolados
//	{
//		int v = q.front(); q.pop(); // Desencolar un vértice v
//		for (int i = 0; i < (int)g[v].size(); i++) // Ir a los vecinos
//		{
//			int u = g[v][i];  // Arista v  u
//			if (color[u] == 0) // Si el vértice no fue visitado..
//			{
//				q.push(u); // Encolar el vértice u
//				dist[u] = dist[v] + 1; // Actualizar la distancia
//				parent[u] = v; // Actualizar el padre del vértice u
//				color[u] = 1;  // Marcar el vértice u como visitado
//			}
//		}
//		color[v] = 2; // Marcar el vértice v como procesado
//	}
//}
//
//void printPath(int start, int end)
//{
//	// Si end es -1, no existe un camino directo
//	if (start == end || end == -1)
//	{
//		cout << start;
//		return;
//	}
//	printPath(start, parent[end]);
//	cout << " " << end;
//}
//
//
//// BFS Matriz
//
//#define MAXR 1005
//#define MAXC 1005
//#define INF 20000000
//typedef pair<int, int> ii; // Par de enteros
//// 4 direcciones: derecha, izquierda, abajo, arriba
//int aux_x[4] = { 0, 0, 1, -1 };
//int aux_y[4] = { 1, -1, 0, 0 };
//int R, C; // (R x C): Tamaño de la matriz
//int color[MAXR][MAXC];//0: no visitado, 1: visitado, 2: procesado
//int dist[MAXR][MAXC]; //dist[x][y]: Distancia de (x,y) a la raíz
//
//void init()
//{
//	for (int i = 0; i < R; i++)
//		for (int j = 0; j < C; j++)
//		{
//			color[i][j] = 0;  // el vértice no ha sido visitado
//			dist[i][j] = INF; // imposibilidad de llegar al vértice
//		}
//}
//void bfs(int px, int py) // (px,py): Celda raíz
//{
//	queue<ii> q; q.push(ii(px, py)); // Encolar la celda raíz   
//	color[px][py] = 1; // Marcar la celda como visitada
//	dist[px][py] = 0;  // La distancia de una celda a sí misma es 0 
//	while (!q.empty())  // Mientras existan celdas encoladas..
//	{
//		int x = q.front().first;  // Obtener coordenada x de la celda
//		int y = q.front().second; // Obtener coordenada y de la celda      
//		q.pop(); // Desencolar una celda
//		for (int i = 0; i < 4; i++) // Para cada celda adyacente..
//		{
//			int nx = x + aux_x[i]; // Calcular nueva coordenada x
//			int ny = y + aux_y[i]; // Calcular nueva coordenada y
//			if (nx > -1 && ny > -1 && nx < R && ny < C &&
//				color[nx][ny] == 0) // Pueden haber validaciones extras
//			{
//				q.push(ii(nx, ny)); // Encolar la celda (nx,ny)
//				color[nx][ny] = 1; // Marcar la celda como visitada
//				dist[nx][ny] = dist[x][y] + 1; // Actualizar la distancia 
//			}
//		}
//		color[x][y] = 2;  // Marcar la celda como procesada
//	}
//}
//
////BFS Multiplos Origenes
//void bfs(const vector<int>& r) // r: Vértices raíces
//{
//	queue<int> q; // Cola de vértices
//	for (int i = 0; i < (int)roots.size(); i++) // Para cada raíz..
//	{
//		q.push(r[i]);    // Encolar una raíz
//		color[r[i]] = 1; // Marcar el vértice como visitado
//		dist[r[i]] = 0;  // La distancia de una raíz a sí misma es 0
//	}
//	// El resto del código se mantiene…
//}
//
//// Quicksort
//// Función para dividir el array y hacer los intercambios
//int divide(int *array, int start, int end) {
//	int left;
//	int right;
//	int pivot;
//	int temp;
//
//	pivot = array[start];
//	left = start;
//	right = end;
//
//	// Mientras no se cruzen los índices
//	while (left < right) {
//		while (array[right] > pivot) {
//			right--;
//		}
//
//		while ((left < right) && (array[left] <= pivot)) {
//			left++;
//		}
//
//		// Si todavía no se cruzan los indices seguimos intercambiando
//		if (left < right) {
//			temp = array[left];
//			array[left] = array[right];
//			array[right] = temp;
//		}
//	}
//
//	// Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
//	temp = array[right];
//	array[right] = array[start];
//	array[start] = temp;
//
//	// La nueva posición del pivot
//	return right;
//}
//
//// Función recursiva para hacer el ordenamiento
//void quicksort(int *array, int start, int end)
//{
//	int pivot;
//
//	if (start < end) {
//		pivot = divide(array, start, end);
//
//		// Ordeno la lista de los menores
//		quicksort(array, start, pivot - 1);
//
//		// Ordeno la lista de los mayores
//		quicksort(array, pivot + 1, end);
//	}
//}
//int main()
//{
//	int const MAX = 100;
//	int arraySize;
//
//	clock_t start_time;
//	clock_t final_time;
//	double total_time;
//	start_time = clock();
//
//	cout << "Ingresa tamanyo: " << endl;
//	cin >> arraySize;
//
//	int a[arraySize];
//
//	// Para que el rand no genere siempre los mismos números, utilizando la hora del sistema
//	srand(time(0));
//
//	// Para generar enteros aleatorios usamos rand()
//	for (int i = 0; i < arraySize; i++) {
//		a[i] = rand() % MAX;
//	}
//
//	cout << "Array antes de ordenarse: " << endl;
//	for (int i = 0; i < arraySize; i++) {
//		cout << a[i] << " ";
//	}
//
//	cout << endl << endl;
//
//	quicksort(a, 0, arraySize - 1);
//
//	final_time = clock();
//	total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;
//
//	printf("Tiempo de ejecución : %lf segundos \n", total_time);
//
//	cout << "Array ordenado " << endl;
//	for (int i = 0; i < arraySize; i++) {
//		cout << a[i] << "-";
//	}
//
//	cout << endl << endl;
//
//	return 0;
//}
//
////Brute Force
//vector<int> v;
//do
//{
//	for (int i = 0; i < (int)v.size(); i++)
//		cout << v[i];
//	cout << endl;
//} while (next_permutation(v.begin(), v.end());
//
//// N Reinas
//#define N 4 
//#include<stdio.h> 
//#include<stdbool.h> 
//
///* A utility function to print solution */
//void printSolution(int board[N][N])
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//			printf(" %d ", board[i][j]);
//		printf("\n");
//	}
//}
//
///* A utility function to check if a queen can
//   be placed on board[row][col]. Note that this
//   function is called when "col" queens are
//   already placed in columns from 0 to col -1.
//   So we need to check only left side for
//   attacking queens */
//bool isSafe(int board[N][N], int row, int col)
//{
//	int i, j;
//
//	/* Check this row on left side */
//	for (i = 0; i < col; i++)
//		if (board[row][i])
//			return false;
//
//	/* Check upper diagonal on left side */
//	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
//		if (board[i][j])
//			return false;
//
//	/* Check lower diagonal on left side */
//	for (i = row, j = col; j >= 0 && i < N; i++, j--)
//		if (board[i][j])
//			return false;
//
//	return true;
//}
//
///* A recursive utility function to solve N
//   Queen problem */
//bool solveNQUtil(int board[N][N], int col)
//{
//	/* base case: If all queens are placed
//	  then return true */
//	if (col >= N)
//		return true;
//
//	/* Consider this column and try placing
//	   this queen in all rows one by one */
//	for (int i = 0; i < N; i++)
//	{
//		/* Check if the queen can be placed on
//		  board[i][col] */
//		if (isSafe(board, i, col))
//		{
//			/* Place this queen in board[i][col] */
//			board[i][col] = 1;
//
//			/* recur to place rest of the queens */
//			if (solveNQUtil(board, col + 1))
//				return true;
//
//			/* If placing queen in board[i][col]
//			   doesn't lead to a solution, then
//			   remove queen from board[i][col] */
//			board[i][col] = 0; // BACKTRACK 
//		}
//	}
//
//	/* If the queen cannot be placed in any row in
//	   this colum col  then return false */
//	return false;
//}
//
///* This function solves the N Queen problem using
//   Backtracking. It mainly uses solveNQUtil() to
//   solve the problem. It returns false if queens
//   cannot be placed, otherwise, return true and
//   prints placement of queens in the form of 1s.
//   Please note that there may be more than one
//   solutions, this function prints one  of the
//   feasible solutions.*/
//bool solveNQ()
//{
//	int board[N][N] = { {0, 0, 0, 0},
//		{0, 0, 0, 0},
//		{0, 0, 0, 0},
//		{0, 0, 0, 0}
//	};
//
//	if (solveNQUtil(board, 0) == false)
//	{
//		printf("Solution does not exist");
//		return false;
//	}
//
//	printSolution(board);
//	return true;
//}
//
//// driver program to test above function 
//int main()
//{
//	solveNQ();
//	return 0;
//}
