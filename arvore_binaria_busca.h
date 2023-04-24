typedef struct arvore Arvore;
typedef struct no No;

struct arvore{
    No *raiz;
};

struct no{
    int chave;
    struct no *esq;
    struct no *dir;  
};

Arvore** cria_array_poteiros(int);
Arvore* cria_arvore_vazia();
No* cria_no(int);
void insere(Arvore*, int);
void insere_com_elementos(No*, int);
void pre_ordem(No*);
void destroi(No*);