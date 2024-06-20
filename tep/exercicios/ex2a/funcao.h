#ifndef FUNCAO_H
#define FUNCAO_H

typedef struct matriz Mat;

Mat* CriaMat(int l, int c);
void PreencheMat(Mat *matriz);
void ImprimeMat(Mat* matriz);
void Desaloca(Mat* matriz);


#endif