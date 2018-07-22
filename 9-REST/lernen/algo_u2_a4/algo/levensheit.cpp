#include "levensheit.h"
#include <iostream>
int minimal(int *D, std::string *original , std::string *katze, int i, int j){
	int ersteChar = 0;
    int n = original->size()+1;
    //int m = katze->size();
    i++;
    j++;
   // ausgabe(D,original,katze);
    //std::cout << "INDEX:" << i-1 << std::endl;
    //std::cout << "INDEX:" << j-1 << std::endl;
    //std::cout << original->at(i-1) << " == "<< katze->at(j-1)  << std::endl;

	if(original->at(i-1)!=katze->at(j-1)){
		ersteChar = 1;
	}
    /*std::cout << ersteChar << std::endl;
    std::cout << (D[(i-1)*n+j]+1) << std::endl;
    std::cout << (D[i*n+(j-1)]+1) << std::endl;
        */
    int a = ((D[(j-1)*n+i]+1) < (D[j*n+(i-1)]+1))?(D[(j-1)*n+i]+1):(D[j*n+(i-1)]+1);
    //std::cout << "INDEX:" << (j-1)*n+i << std::endl;
    //std::cout << "INDEX:" << j*n+(i-1) << std::endl;
    //std::cout <<"x: "<< (D[(j-1)*n+i]+1) << " < " << (D[j*n+(i-1)]+1) << " = " << a <<std::endl;
	int x = ((D[(j-1)*n+i]+1) < (D[j*n+(i-1)]+1))?(D[(j-1)*n+i]+1):(D[j*n+(i-1)]+1);
	int b =  (x < (D[(j-1)*n+(i-1)]+ersteChar))?x:(D[(j-1)*n+(i-1)]+ersteChar);
    //std::cout << "INDEX:" << (j-1)*n+i << std::endl;
    //std::cout << "INDEX:" << j*n+(i-1) << std::endl;
    //std::cout <<i <<"/" << i << " :=> " << x <<" < " << (D[(j-1)*n+(i-1)]+ersteChar) << " = " << b <<std::endl;
	D[j*n+i] = (x < (D[(j-1)*n+(i-1)]+ersteChar))?x:(D[(j-1)*n+(i-1)]+ersteChar);
	//std::cout << "INDEX:" << j*n+i << std::endl;
    ausgabe(D,original,katze);
	return D[j*n+(i)];
}


int levenshtein_distance(std::string original, std::string katze){
    int zwischenSpeicher = 0; // ZwischenSpeicher;
    int n = original.size();
    int m = katze.size();
    int *D = new int[(n+1) * (m+1)]{0};
        for(int x=1; x<=n; x++){
            D[x]=x;
        }
        for(int x=1; x<=m; x++){
            D[x*(n+1)]=x;
        }
    for(int g=0; g<n; g++){
        for(int x=0; x<m; x++){
           // std::cout << g << "/" << x << "  ";
             zwischenSpeicher = minimal(D, &original, &katze, g, x);
        }
    // std::cout << std::endl;
    }
    //ausgabe(D, &original, &katze);
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

