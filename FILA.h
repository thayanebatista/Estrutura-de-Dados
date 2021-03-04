#include <iostream>

using namespace std;


struct noFila {
    int chave;
    noFila *prox;
};

struct Fila {
    noFila *ini, *fim;
};

void inicia_fila(Fila &F) {
    F.ini = NULL;
    F.fim = NULL;
}

bool fila_vazia(Fila F) {
    return F.ini == NULL;
}

noFila *busca_inicio(Fila F) {
    return F.ini;
}

void insere_fila(Fila &F, int x) {
    noFila *novo;
    novo = new noFila;

    if(novo != NULL) {
        novo->chave = x;
        if (fila_vazia(F)) {
            F.ini = novo;
        }else {
            F.fim->prox = novo;
        }
        novo->prox = NULL;
        F.fim = novo;
    }else{
        cout<<"****** OVERFLOW ******"<<endl;
    }
}

noFila *remove_fila(Fila &F) {
    noFila *aux;
    aux = NULL;

    if(!fila_vazia(F)) {
        aux = F.ini;
        F.ini = F.ini->prox;
        aux->prox = NULL; // ISOLA

    }else{
        cout<<"****** UNDERFLOW ******"<<endl;
    }
    return aux;
}

void imprime_fila(Fila F) {
    if (!fila_vazia(F)) {
        noFila *aux = F.ini;
        while ( aux != NULL ) {
            cout<<"["<<aux->chave<<"]";
            aux = aux->prox;
        }
    }else {
        cout<<"******* FILA VAZIA *******";
    }
    cout<<endl;
}

void menu_fila(Fila &F) {
    int opcao = -1; // CONTROLA O MENU
    int x; // ARMAZENA O VALOR PARA INSERIR

    while (opcao != 0) {
            system("cls");
        cout<<"********************************"<<endl
            <<"*            FILA              *"<<endl
            <<"********************************"<<endl
            <<endl
            <<"******* MENU *******"<<endl
            <<"*                  *"<<endl
            <<"* 1. INSERE        *"<<endl
            <<"* 2. REMOVE        *"<<endl
            <<"* 3. IMPRIME FILA  *"<<endl
            <<"* 4. BUSCA INICIO  *"<<endl
            <<"* 0. SAIR          *"<<endl
            <<"*                  *"<<endl
            <<"********************"<<endl
            <<">>>>> ";
        cin>>opcao;

        switch (opcao){
        case 1:
            system("cls");
            cout<<"********************************"<<endl
                <<"*        FILA - INSERE        *"<<endl
                <<"********************************"<<endl
                <<endl<<"DIGITE O VALOR A SER INSERIDO: ";
                cin>>x;
                insere_fila(F,x);
                cout<<endl;
                //imprime_pilha(p);
                //system("pause");
                break;
        case 2:
            system("cls");
            cout<<"********************************"<<endl
                <<"*        FILA - REMOVE        *"<<endl
                <<"********************************"<<endl
                <<endl;
                cout<<"FILA ANTES DA REMOÇÃO: "<<endl;
                imprime_fila(F);
                cout<<endl;
                remove_fila(F);
                cout<<"FILA DEPOIS DA REMOÇÃO: "<<endl;
                cout<<endl;
                imprime_fila(F);
                system("pause");
                break;
        case 3:
            system("cls");
            cout<<"********************************"<<endl
                <<"*      FILA - EXIBE FILA     *"<<endl
                <<"********************************"<<endl
                <<endl;
                imprime_fila(F);
                cout<<endl;
                system("pause");
                break;
        case 4:
            system("cls");
            cout<<"********************************"<<endl
                <<"*      FILA - BUSCA INCIO      *"<<endl
                <<"********************************"<<endl
                <<endl;
                noFila *a;
                a = busca_inicio(F);
                if(a != NULL){
                    cout<<"INICIO DA FILA: "<<a->chave<<endl;
                } else {
                    cout<<"******FILA VAZIA******"<<endl;
                }
                cout<<endl;
                system("pause");
                break;
        case 0:
            system("cls");
            cout<<"****** OBRIGADA ******"<<endl<<endl;
            break;

        default:
            system("cls");
            cout<<"******INFORME UMA OPCAO VALIDA******"<<endl<<endl<<endl;
            cout<<"VOLTANDO AO MENU...."<<endl<<endl;
            system("pause");
            }
        }
    }
