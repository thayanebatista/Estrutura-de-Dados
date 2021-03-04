#include <iostream>

using namespace std;


struct noListaSECND
{
    int chave;
    noListaSECND *prox;
};

struct ListaSECND
{
    noListaSECND *descritor;
};


void inicializa_lista(ListaSECND &l)
{
    noListaSECND *novo = new noListaSECND();
    if (novo==NULL)
    {
        cout<<"\nLista Cheia\n";
    }
    else
    {
        novo->prox = novo;
        l.descritor = novo;
    }
}


bool lista_vazia(ListaSECND &l)
{
    return (l.descritor==l.descritor->prox);
}


noListaSECND* busca_lista(ListaSECND &l, int x)
{
    if (lista_vazia(l))
    {
        return NULL;
    }
    else
    {
        noListaSECND *no;
        no = l.descritor->prox;
        l.descritor->chave = x;
        while (no->chave!=l.descritor->chave)
        {
            no = no->prox;
        }
        if (no!=l.descritor)
        {
            return no;
        }
        else
        {
            return NULL;
        }
    }
}


void inserefim_lista(ListaSECND &l, int x)
{
    noListaSECND *novo = new noListaSECND();
    noListaSECND *aux;

    if(novo == NULL)
    {
        cout<<"\n  Lista Cheia\n";
    }
    else
    {
        aux = l.descritor->prox;
        while (aux->prox!=l.descritor)
        {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
        novo->chave = x;
    }
}


void insereinicio_lista(ListaSECND &l, int x)
{
    noListaSECND *novo = new noListaSECND();

    if(novo == NULL)
    {
        cout<<"\n   Lista Cheia  \n";
    }
    else
    {
        novo->chave = x;
        novo->prox = l.descritor->prox;
        l.descritor->prox = novo;
    }
}


void insereordenado_lista(ListaSECND &l, int x)
{
    if (lista_vazia(l) || l.descritor->prox->chave >= x)
    {
        insereinicio_lista(l,x);
    }
    else
    {
        noListaSECND *novo = new noListaSECND();
        noListaSECND *aux;
        if(novo == NULL)
        {
            cout<<"\n   LISTA CHEIA  \n";
        }
        else
        {
            l.descritor->chave = x;
            aux = l.descritor;

            while (aux->prox->chave < x)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            novo->chave = x;
        }
    }
}

noListaSECND* remove_lista(ListaSECND &l, int x)
{
    if (!lista_vazia(l))
    {
        noListaSECND *no,*aux;
        no = busca_lista(l,x);

        if(no == NULL)
        {
            return NULL;
        }
        else
        {
            aux = l.descritor;
            while (aux->prox!=no)
            {
                aux = aux->prox;
            }
            aux->prox=no->prox;
        }
        return no;
    }
    else
    {
        cout<<"\n     Lista Vazia!   "<<endl;
        system("pause");
        return NULL;
    }
}

void inseresemrepeticao_lista(ListaSECND &l, int x)
{
    if (busca_lista(l,x)==NULL)
    {
        insereinicio_lista(l,x);
    }
    else
    {
        cout<<"\n    NAO FOI POSSIVEL INSERIR, ELEMENTO JA EXISTENTE \n\n";
        system("pause");
    }
}


void imprime_lista(ListaSECND &l)
{
    noListaSECND *aux;
    if (lista_vazia(l))
    {
        cout<<"\n   LISTA VAZIA \n";
        system("pause");
        return;
    }

    aux = l.descritor->prox;

    system("cls");

    cout<<endl<<"   ";
    while (aux != l.descritor)
    {
        cout<<aux->chave<<" | ";
        aux = aux->prox;
    }
    cout<<endl<<endl;
    system("pause");
}


