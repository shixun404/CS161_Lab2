#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define N 1000

int initialize(double * matrix);
int _initialize(double * matrix);

int main()
{
	int i, j, k;
	double *A, *B, *C1, *C2, *C3;
	struct timeval start, end;
	double timeCost;

	A=(double *)malloc(sizeof(double)*N*N);
	B=(double *)malloc(sizeof(double)*N*N);
	C1=(double *)malloc(sizeof(double)*N*N);
	C2=(double *)malloc(sizeof(double)*N*N);
	C3=(double *)malloc(sizeof(double)*N*N);

	initialize(A);
	initialize(B);
	_initialize(C1);
	_initialize(C2);
	_initialize(C3);

	// Version 1
	gettimeofday(&start, NULL);
	for(i=0; i<N; i++)
	    for(j=0; j<N; j++)
		    for(k=0; k<N; k++)
		        C1[i*N+j]+=A[i*N+k]*B[k*N+j];
	gettimeofday(&end, NULL);

	timeCost=1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
	timeCost/=1000000;
        printf("Version-1 costs %lf seconds\n", timeCost);

	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	// Version 2
	gettimeofday(&start, NULL);
	/* 
		To be filled by student.
	*/ 
	gettimeofday(&end, NULL);

	timeCost=1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
	timeCost/=1000000;
	printf("Version-2 costs %lf seconds\n", timeCost);
	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	// Version 3
	gettimeofday(&start, NULL);
	/* 
		To be filled by student.
	*/ 
	gettimeofday(&end, NULL);

	timeCost=1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
	timeCost/=1000000;
	printf("Version-2 costs %lf seconds\n", timeCost);
	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	// verification
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++) {
            if (C1[i*N+j] - C2[i*N+j] < 0.000001)
                continue;
            else {
                printf("Version 2 ERRORS DETECTED!!!!!!!!!!!!!\n");
                return -1;
            }
        } 

	
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++) {
            if (C1[i*N+j] - C3[i*N+j] < 0.000001)
                continue;
            else {
                printf("Version 3 ERRORS DETECTED!!!!!!!!!!!!!\n");
                return -1;
            }
        } 

	// release resources and return
	free(A);
	free(B);
	free(C1);
	free(C2);
	free(C3);
	
	return 0;
}


int initialize(double * matrix)
{
	int i=0,j=0;
	srand((unsigned)time(NULL));
	for( i=0; i<N; i++)
	  for(j=0; j<N; j++)
	  {
		  matrix[i*N+j]=rand()/3000.0;
	  }
	printf("Initialized successfully!\n");
	return 0;
}

int _initialize(double * matrix)
{
	int i=0, j=0;
	for(i=0; i<N; i++)
	  for(j=0; j<N; j++)
	  {
		  matrix[i*N+j]=0.0;
	  }
	printf("Initialized successfully!\n");
	return 0;
}
