#include <bits/stdc++.h>

using namespace std; 

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 



#define vi std::vector<int> 
#define stin std::stack<int>
#define pii std::pair<int, int>
#define isOn(N, i) (N & (1 << i)) 
#define endl '\n' 
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
#define N_MAX 20000
#define mid(i,j) (i+j)/2


class SegmentTree
{
private: 
	//st[p] = orderder_set correspondiente al sub arreglo con el identificador p
	// los hijos de p tendran id p*2 y p*2 + 1 como izquierdo y derecho, respectivamente. 
	std::vector<ordered_set>  st; 

	//A[i] = valor del indice i en el arreglo original
	vi A; 
	//ordered_set A2; 
	int n; 
	int left (int p) {return p << 1;} 
	int right(int p) {return (p << 1) + 1;} 

	void build (int p, int L, int R)
	{
		//Si el arreglo tiene un unico valor, lo agregamos al arbol que corresponde a su posicion
		if (L == R)
			st[p].insert({A[L], L});  

		// En caso de que arreglo tenga mas de un solo elemento
		else
		{
			//bajamos recursivamente hasta los nodo hojas para construir los sub arreglos, 
			//Usamos left y right para identificar a los sub arreglos
			build (left(p), L, (L+R)/2); 
			build (right(p), (L+R)/2 + 1, R); 

			//Definimos los hijos del arreglo actual 
			int p1 = left(p), p2 = right(p); 

			// Insertamos todos los elementos de los hijos
			
			st[p] = st[left(p)]; 

			for(auto i: st[right(p)])
				st[p].insert(i); 
			
		}
	} 

	//Buscaremos los sub arreglos que al unirlos coincidan con el rango que nos interesa
	//p es el identificador del orderder_set
	//L-R es el rango sobre el cual se va a buscar
	//i-j es el rango de interes
	//buscamos el k-esimo elemento en el subarreglo [i-j] ordenado. 
	int new_rmq (int p, int L, int R, int i, int j, int v)  
	{
		if(R < i || j < L)
			return 0; 
		if(i <= L && R <= j) return st[p].order_of_key({v+1, -1}); 

		int mid = mid(i,j); 
		int p1 = new_rmq(left(p), L, mid, i, j, v); 
		int p2 = new_rmq(right(p), mid + 1, R, i, j, v); 

		return p1 + p2; 
	}


	int busqueda_binaria (int i, int j, int k) 
	{
		if (i == j) return i; 
		
		int mid = mid(i,j); 

		int posicion = new_rmq(1, 0, n-1, i, j, k); 
		
		if(posicion <= mid) 
			return busqueda_binaria(i, mid, k); 
		else
			return busqueda_binaria(mid + 1, j, k); 
	}

	void update (int pos, int val, int p)
	{

		if(st[p].size() == 1) 
			A[pos] = val; 


		st[p].erase({A[pos], pos});
		st[p].insert({val, pos}); 

		if(st[left(p)].find({A[pos], pos}) != st[left(p)].end())
			update(pos, val, left(p)); 

		if(st[right(p)].find({A[pos], pos}) != st[right(p)].end())
			update(pos, val, right(p)); 

		return; 


		
	}



public:
	SegmentTree(const vi &_A)
	{
		A = _A;  
		n = (int)A.size(); 
		st.assign(4 * n, ordered_set());
		build (1, 0 , n-1); 
	}



	int ans (int i, int j, int k) {return A[busqueda_binaria(i, j, k)];} 

	void update (int pos, int val) {return update(pos, val, 1);}



	//~SegmentTree();
	
};


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int N, M, tmp, k; 

	std :: cin >> N; 	

	vi  datos; 
	for (int i = 0; i < N ; ++i)
	 std::cin >> k,  datos.push_back(k); 

	SegmentTree st(datos); 

	std::cin >> M; 
	//std::cout << M; 

	int l, r,  idx, val;  

	for (int i = 0; i < M ; ++i)
	{
	
		std::cin >> tmp; 

		switch(tmp)
		{
			case 0: 
				std::cin >> l >>  r >>  k;
				cout <<  i << "---" << l << "---" <<  r << "---" <<  k  << endl; 
				std::cout << st.ans(l, r, k) << endl;
				
			break;
		
			case 1: 
				std::cin >> idx >>  val;
				cout  << i << "---" << idx << "---" << val << endl;
				st.update(idx, val);
			break; 
		}

	}


	return 0;
}