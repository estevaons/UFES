
#ifdef TYPE
#ifdef TYPED

typedef struct TYPED(complexo){
    TYPE num1;
    TYPE num2;
}TYPED(tComplexo);

//typedef struct num_complexo tComplexo;
void TYPED(CrieNumeroComplexo)(TYPED(tComplexo) **pointer);
void TYPED(PreencheComplexoDeReais)(TYPED(tComplexo) *pointer, TYPE num1, TYPE num2);
TYPED(tComplexo) TYPED(SomaComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q);
TYPED(tComplexo) TYPED(ProdutoComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q);
TYPED(tComplexo)  TYPED(SubtracaoComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q);
TYPED(tComplexo)  TYPED(DivisaoComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q);

void TYPED(ApresentaComplexo)(TYPED(tComplexo) op);

void TYPED(DesalocaMemoria)(TYPED(tComplexo) *pointer);


#endif
#endif
