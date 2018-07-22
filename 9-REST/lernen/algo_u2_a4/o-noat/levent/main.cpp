#include <iostream>
#include <string>
int minimal(int*, std::string*, std::string*, int, int);
int levenshtein_distance(std::string, std::string);
void ausgabe(int *, std::string *, std::string *);  // DEBUG-Zweck

int minimal(int *D, std::string *original , std::string *katze, int i, int j){
	i++;  // Wenn i und j >= 0, zwar laut wiki >= 1
    j++;
	int ersteChar = 0;
    int n = original->size()+1;

    /*
        int m = katze->size();
        ausgabe(D,original,katze);
        std::cout << "INDEX:" << i-1 << std::endl;
        std::cout << "INDEX:" << j-1 << std::endl;
        std::cout << original->at(i-1) << " == "<< katze->at(j-1)  << std::endl;
    */

	if(original->at(i-1)!=katze->at(j-1)){
		ersteChar = 1;
	}

    /*
        std::cout << ersteChar << std::endl;
        std::cout << (D[(i-1)*n+j]+1) << std::endl;
        std::cout << (D[i*n+(j-1)]+1) << std::endl;
        int a = ((D[(j-1)*n+i]+1) < (D[j*n+(i-1)]+1))?(D[(j-1)*n+i]+1):(D[j*n+(i-1)]+1);
        std::cout << "INDEX:" << (j-1)*n+i << std::endl;
        std::cout << "INDEX:" << j*n+(i-1) << std::endl;
        std::cout <<"x: "<< (D[(j-1)*n+i]+1) << " < " << (D[j*n+(i-1)]+1) << " = " << a <<std::endl;
    */

	int x = ((D[(j-1)*n+i]+1) < (D[j*n+(i-1)]+1))?(D[(j-1)*n+i]+1):(D[j*n+(i-1)]+1); // IF(a<b){a}else{b}

	/*
        int b =  (x < (D[(j-1)*n+(i-1)]+ersteChar))?x:(D[(j-1)*n+(i-1)]+ersteChar);
        std::cout << "INDEX:" << (j-1)*n+i << std::endl;
        std::cout << "INDEX:" << j*n+(i-1) << std::endl;
        std::cout <<i <<"/" << i << " :=> " << x <<" < " << (D[(j-1)*n+(i-1)]+ersteChar) << " = " << b <<std::endl;
    */

	//D[j*n+i] = (x < (D[(j-1)*n+(i-1)]+ersteChar))?x:(D[(j-1)*n+(i-1)]+ersteChar); // IF(a<b){a}else{b}

	/*
        std::cout << "INDEX:" << j*n+i << std::endl;
        ausgabe(D,original,katze);
    */
	return (x < (D[(j-1)*n+(i-1)]+ersteChar))?x:(D[(j-1)*n+(i-1)]+ersteChar);
}


int levenshtein_distance(std::string original, std::string katze){
    int zwischenSpeicher = 0; // ZwischenSpeicher;
    int n = original.size();  // String länge
    int m = katze.size();	// String länge 2
    int *D = new int[(n+1) * (m+1)]{0}; // dyn. Array
        for(int x=0; x<=n; x++){ // Horizontal 1 bis n
            D[x]=x;
        }
        for(int x=0; x<=m; x++){ // Vertical 1 bis m
            D[x*(n+1)]=x;
        }
    for(int g=0; g<n; g++){
        for(int x=0; x<m; x++){
        /*
            std::cout << g << "/" << x << "  ";
        */

             D[(x+1)*(n+1)+(g+1)] = minimal(D, &original, &katze, g, x);
        }
        /*
            std::cout << std::endl;
        */

    }


        ausgabe(D, &original, &katze);
    zwischenSpeicher = D[(m)*(n+1)+n];
    delete[] D;
    return zwischenSpeicher;
}

void ausgabe(int *D, std::string *original , std::string *katze){
    int n = original->size();
    int m = katze->size();
    std::cout << "--------------" << std::endl;
    for(int u = 0; u<=m; u++){
    for(int h = 0; h<=n; h++){
        //std::cout << u << "/" << h << " ";
        std::cout << D[u*(n+1)+h] << " - ";
    }
    std::cout << std::endl;
    }
    std::cout << "--------------" << std::endl;
}

int main(){
    std::cout << levenshtein_distance("head","cat");
return 0;
}

