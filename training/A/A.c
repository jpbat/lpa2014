#include <stdio.h>
#include <string.h>

int X,Y;

char t[101][101];
char e[101][101];
/*int a[5000][2];*/

#define BAR1 '\\'
#define BAR0 '/'

int valide(int x,int y){
	if (x>X || y>Y)
		return 0;
	return 1;
}

int run(int x,int y/*, int p*/, char d){
	char c=t[x][y];
	/*t[x][y]='#';*/
	if (x==X-1){
		printf("(%d,%d)",X-x,y+1);
		/*a[p][0]=x;
		a[p][1]=y;
		a[p+1][0]=-1;*/
		return 1;
	}

	/*printf("(%d,%d) %d\n",x+1,y+1,x);*/
	if (t[x][y]=='|')
		t[x][y]='#';
	else if (e[x][y]==d)
		return 0;
	else if(e[x][y]!=t[x][y])
		t[x][y]='#';
	else
		e[x][y]=d;

	if (c==BAR0){
		if (d=='X'){
			if(valide(x+1,y) && t[x+1][y]==BAR1)
				if(run(x+1,y/*,p+1*/,'X')){
					printf(",(%d,%d)",X-x,y+1);
					/*a[p][0]=x;
					a[p][1]=y;*/
					return 1;
				}
			if(valide(x+1,y+1) && (t[x+1][y+1]==BAR0 || t[x+1][y+1]=='|'))
				if(run(x+1,y+1/*,p+1*/,'X')){
					printf(",(%d,%d)",X-x,y+1);
					/*a[p][0]=x;
					a[p][1]=y;*/
					return 1;
				}
			if(valide(x,y+1) && t[x][y+1]==BAR1)
				if(run(x,y+1/*,p+1*/,'0')){
					printf(",(%d,%d)",X-x,y+1);
					/*a[p][0]=x;
					a[p][1]=y;*/
					return 1;
				}
		}else if(valide(x,y-1) && t[x][y-1]==BAR1)
			if(run(x,y-1/*,p+1*/,'X')){
				printf(",(%d,%d)",X-x,y+1);
				/*a[p][0]=x;
				a[p][1]=y;*/
				return 1;
			}
	}else if (c==BAR1){
		if (d=='X'){
			if(valide(x+1,y) && t[x+1][y]==BAR0)
				if(run(x+1,y/*,p+1*/,'X')){
					printf(",(%d,%d)",X-x,y+1);
					/*a[p][0]=x;
					a[p][1]=y;*/
					return 1;
				}
			if(valide(x+1,y-1) && (t[x+1][y-1]==BAR1 || t[x+1][y-1]=='|'))
				if(run(x+1,y-1/*,p+1*/,'X')){
					printf(",(%d,%d)",X-x,y+1);
					/*a[p][0]=x;
					a[p][1]=y;*/
					return 1;
				}
			if(valide(x,y-1) && t[x][y-1]==BAR0)
				if(run(x,y-1/*,p+1*/,'0')){
					printf(",(%d,%d)",X-x,y+1);
					/*a[p][0]=x;
					a[p][1]=y;*/
					return 1;
				}
		}else if(valide(x,y+1) && t[x][y+1]==BAR0)
			if(run(x,y+1/*,p+1*/,'X')){
				printf(",(%d,%d)",X-x,y+1);
				/*a[p][0]=x;
				a[p][1]=y;*/
				return 1;
			}
		
	}else if (c=='|'){
		if(valide(x+1,y) && t[x+1][y]=='|')
			if(run(x+1,y/*,p+1*/,'X')){/*indiferente*/
				printf(",(%d,%d)",X-x,y+1);
				/*a[p][0]=x;
				a[p][1]=y;*/
				return 1;
			}
		if(valide(x+1,y+1) && t[x+1][y+1]==BAR0)
			if(run(x+1,y+1/*,p+1*/,'X')){
				printf(",(%d,%d)",X-x,y+1);
				/*a[p][0]=x;
				a[p][1]=y;*/
				return 1;
			}
		if(valide(x+1,y-1) && t[x+1][y-1]==BAR1)
			if(run(x+1,y-1/*,p+1*/,'X')){
				printf(",(%d,%d)",X-x,y+1);
				/*a[p][0]=x;
				a[p][1]=y;*/
				return 1;
			}
	}
	return 0;
}

int main(){
	int i,s;

	while(scanf("%d",&X)!=-1){
		s=1;
		scanf("%d",&Y);
		for (i=X-1; i>=0 ; --i){
			scanf("%s\n",t[i]);
			memset (e[i],0,Y);
			/*strcpy(e[i],t[i]);*/
		}
		
		for (i=0; i<Y; ++i){
			if (t[0][i]==BAR1 || t[0][i]=='|' || t[0][i]==BAR0){
				if(run(0,i/*,0*/,'X')){/*indiferente*/
					/* imprimir coordenadas*/
					/*printf("(%d,%d)",a[0][0]+1,a[0][1]+1);
					for(i=1; a[i][0]!=-1; ++i){
						printf(",(%d,%d)",a[i][0]+1,a[i][1]+1);
					}*/
					printf("\n");
					s=0;
					break;
				}
			}
		}
		if (s)
			printf("No Path!\n");
	}
	return 0;
}

