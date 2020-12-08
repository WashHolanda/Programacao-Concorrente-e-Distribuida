// Retorna a quantidade de vizinhos vivos de cada celula na posicao ​i,j
int getNeighbors(int i, int j) {
    int count=0;
    
    #pragma omp parallel 
    {
        #pragma omp sections reduction(+:count) firstprivate(i,j) nowait
        {
            #pragma omp section
            {
                count += grid[i][((j+1)%TAM)]; // direita
            }
            #pragma omp section
            {
                count += grid[((i+1)%TAM)][((j+1)%TAM)]; // direita baixo
            }
            #pragma omp section
            {
                count += grid[((i+1)%TAM)][j]; //baixo
            }
            #pragma omp section
            {
                count += grid[((i+1)%TAM)][(TAM+(j-1))%TAM]; // esquerda baixo
            }
            #pragma omp section
            {
                count += grid[i][(TAM+(j-1))%TAM]; // esquerda
            }
            #pragma omp section
            {
                count += grid[(TAM+(i-1))%TAM][(TAM+(j-1))%TAM]; //esquerda cima
            }
            #pragma omp section
            {
                count += grid[(TAM+(i-1))%TAM][j]; // cima
            }
            #pragma omp section
            {
                count += grid[(TAM+(i-1))%TAM][((j+1)%TAM)]; // direita cima
            }
        }
    }

    return count;
}