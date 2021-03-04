#include <iostream>

using namespace std;

struct noListaSEC
{
    int chave;
    noListaSEC *prox;
};

struct ListaSEC
{
    noListaSEC *ultimo;
};

void inicializa_lista(ListaSEC &l)
{
    l.ultimo = NULL;
}


bool lista_vazia(ListaSEC &l)
{
    return (l.ultimo==NULL);
}


noListaSEC* busca_lista(ListaSEC &l, int x)
{
    noListaSEC *no,aux;

    if (lista_vazia(l))
    {
        return NULL;
    }
    else
    {
        no = l.ultimo->prox;
        while (no!=l.ultimo && no->chave!=x)
        {
            no = no->prox;
        }
        if (no->chave==x)
        {
            return no;
        }
        else
        {
            return NULL;
        }
    }
}


void inserefim_lista(ListaSEC &l, int x)
{
    noListaSEC *novo = new noListaSEC();

    if(novo == NULL)
    {
        cout<<"\nLista Cheia\n";
    }
    else
    {
        novo->chave = x;
        if (lista_vazia(l))
        {
            novo->prox = novo;
        }
        else
        {
            novo->prox = l.ultimo->prox;
            l.ultimo->prox = novo;
        }
        l.ultimo = novo;
    }
}


void insereinicio_lista(ListaSEC &l, int x)
{
    noListaSEC *novo = new noListaSEC();

    if(novo == NULL)
    {
        cout<<"\n   LISTA CHEIA  \n";
    }
    else
    {
        novo->chave = x;
        if (lista_vazia(l))
        {
            novo->prox = novo;
            l.ultimo = novo;
        }
        else
        {
            novo->prox = l.ultimo->prox;
            l.ultimo->prox = novo;
        }
    }
}


void insereordenado_lista(ListaSEC &l, int x)
{
    if (lista_vazia(l))
    {
        insereinicio_lista(l,x);
    }
    else if (l.ultimo->chave <= x)
    {
        inserefim_lista(l,x);
    }
    else
    {
        noListaSEC *novo = new noListaSEC();
        noListaSEC *aux;
        if(novo == NULL)
        {
            cout<<"\n   LISTA CHEIA  \n";
        }
        else
        {
            novo->chave = x;
            aux = l.ultimo;

            while (aux->prox->chave < x)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
}


noListaSEC* remove_lista(ListaSEC &l, int x)
{
    if (!lista_vazia(l))
    {
        noListaSEC *no;
        no = busca_lista(l,x);

        if(no == NULL)
        {
            return NULL;
        }
        else if (l.ultimo->prox==l.ultimo)
        {
            inicializa_lista(l);
        }
        else if (no==l.ultimo->prox)
        {
            l.ultimo->prox = no->prox;
        }
        else
        {
            noListaSEC *aux;
            aux = l.ultimo->prox;
            while (aux->prox!=no)
            {
                aux = aux->prox;
            }
            aux->prox = no->prox;
            if (l.ultimo==no)
            {
                l.ultimo = aux;
            }
        }
        return no;
    }
    else
    {
        cout<<"\n     LISTA VAZIA!   "<<endl;
        system("pause");
        return NULL;
    }
}

void inseresemrepeticao_lista(ListaSEC &l, int x)
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


void imprime_lista(ListaSEC &l)
{
    noListaSEC *aux;
    if (lista_vazia(l))
    {
        cout<<"\n   LISTA VAZIA \n";
        system("pause");
        return;
    }

    aux = l.ultimo->prox;

    system("cls");

    cout<<endl<<"   ";
    while (aux != l.ultimo)
    {
        cout<<aux->chave<<" | ";
        aux = aux->prox;
    }
    cout<<aux->chave;
    cout<<endl<<endl;
    system("pause");
}


