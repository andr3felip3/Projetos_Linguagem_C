#include<stdio.h>
#include<cstdio>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


struct aresta{
    	int fonte,destino,peso;
    	bool operator<(const aresta &v) const{
		return peso<v.peso;
		}
	};


int main() {
	
	
	///////////////////////////
	/*
	priority_queue<int> pq;
	 pq.push(5);
	 pq.push(1);
	 pq.push(3);
	 
	 printf("%d\n",pq.top());
	 pq.pop();
	 printf("%d\n",pq.top());
	 pq.pop();
	 printf("%d\n",pq.top());
	 pq.pop();
	
	if(pq.empty()) printf("Fila vazia\n");
	*/
	//////////////////////////////////////////

    /*
	priority_queue<int, vector<int>, greater<int> >pq;
	
	 pq.push(5);
	 pq.push(1);
	 pq.push(3);
	 
	 printf("%d\n",pq.top());
	 pq.pop();
	 printf("%d\n",pq.top());
	 pq.pop();
	 printf("%d\n",pq.top());
	 pq.pop();
	
	if(pq.empty()) printf("Fila vazia\n");
	
	*/
   ////////////////////////////////	
   /*
priority_queue<aresta> pq;
aresta v,u;
    v.fonte=1;v.destino=2,v.peso=10;
    pq.push(v);
    v.fonte=3;v.destino=5,v.peso=5;
    pq.push(v);
    
    u=pq.top();
    printf("%d\n",u.peso);
*/
//////////////////////////////////////////////
	/*
	set<int> a;
	set<int>::iterator i;
	 
	 a.insert(1); a.insert(3);
	 a.insert(5); a.insert(3);
	 
	 for(i=a.begin();i!=a.end();i++)
	 printf("%3d",*i);
	
	
	i=a.find(2);
   printf("\nEncontrado = %d\n",*i);
   printf("\nThe upper bound of key 3 is = %d\n",*a.upper_bound(3));
   printf("\nThe lower bound of key 3 is = %d\n",*a.lower_bound(3));
   */
 //////////////////////////////////////////////  
 /*
   multiset<int> a,b,c,d,e;
   multiset<int>::iterator i;
   
   a.insert(1); a.insert(3);  a.insert(5);
   b.insert(2); b.insert(3); b.insert(6);
   
   set_union(a.begin(), a.end(),b.begin(),b.end(),inserter(c,c.begin()));
   
   set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(d, d.begin()));
   
   set_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(e,e.begin()));
   
   printf("Uniao\n");
   for(i=c.begin();i!=c.end();i++){
   	printf("%3d",*i);
   }
   
   printf("\nIntersecao\n");
   for(i=d.begin();i!=d.end();i++){
   	printf("%3d",*i);
   }
   
   printf("\nDiferenca\n");
   for(i=e.begin();i!=e.end();i++){
   	printf("%3d",*i);
   }
   
   */
   ///////////////////////////////////////////////////// 
   
     
   	
	
	
	
	return 0;
}
