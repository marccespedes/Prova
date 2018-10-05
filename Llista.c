//Creem la llista Bidireccional Ordenada
LlistaBID LLISTABID_crea(){
  LlistaBID l;
  l.cap = (Node*) malloc (sizeof(Node));
  if(l.cap == NULL){
    printf("Error!\n", );
  }else{
    l.ult = (Node*) malloc(sizeof(Node));
    if (l.ult==NULL){
      printf("Error\n", );
      free(l.cap);
    }else{
      l.pdi = l.ult;
      l.pri->seg = l.ult;
      l.ult->ant = l.cap;
      l.cap->ant = NULL;
      l.ult->seg = NULL;
    }
  }
}

// Tira endarrera una posició
void LLISTABID_retrocedeix (LlistaBID *l){
  if(l->pdi == l->cap){
    printf("No podem anar mes enrere\n", );
  }else{
    l->pdi = l->pdi->ant;
  }
}

element LLISTABID_consulta(LlistaBID l){
  element e;
  e = ELEMENT_indefinit;
  if(l.pdi != l.cap && l.pdi != l.ult){
    e=l.pdi->e;
  }
  return e;
}

void  LLISTABID_esborra(LlistaBID *l){
  Node *aux;
  if(l->pdi == l->cap || l->pdi == l->ult){
    printf("Error\n", );
  }else{
    aux = l->pdi;
    aux->ant->seg = aux->seg;
    aux->seg->ant = aux->ant;
    l->pdi = l.pdi->seg;
    free(aux);
  }
}

void LLISTABID_destrueix(llistaBID *l){
  Node *aux;
  while (l->cap != NULL) {
    aux = l->cap;
    l->cap = l->cap->seg;
    free(aux);
  }
  l->ult = NULL;
  l->pdi = NULL;
}

void LLISTABID_vesinici(LlistaBID *l){
  l->pdi = l->cap->seg;
}

void LLISTABID_inici(llistaBID l){
  return l.pdi == l.cap;
}

void LLISTABID_buida(LlistaBID l){
  return l.cap->seg == l.ult;
}

void LLISTABID_vesfinal(LlistaBID *l){
  l->pdi = l->ult->ant;
}

void LLISTABID_fi(LLISTABID l){
  return l.pdi == l.ult;
}

void LLISTABID_avanca(LlistaBID *l){
  if(l->pdi->seg == NULL){
    printf("No es pot avançar\n", );
  }else{
    l->pdi = l->pdi->seg;
  }
}


void LLISTABID_insereixdavantordenat(llista *l, element e){
  int trobat = 0;
  l->ant = l->pri;
  while (!trobat) {
    if (l->ant->seg->e < e) {
      l->ant = l->ant->seg;
    }
    else{
      trobat = 1;
    }
  }
  insereixdavant(l, e);
}

void LLISTABID_insereixdarreraordenat(llista *l, element e) {
  int trobat = 0;
  l->ant = l->pri;
  while (!trobat) {
    if (l->ant->seg->e < e) {
      l->ant = l->ant->seg;
    }
    else{
      trobat = 1;
    }
  }
  insereixdarrera(l, e);
}

void LLISTABID_insereixdavant(llistaBID *l, element e){
  Node *aux;
  if(l->pdi == l->cap){
    printf("Error\n", );
  }else{
    aux =(Node*) malloc (sizeof(Node));
    if (aux == NULL) {
      printf("Error\n", );
    }else{
      aux->e = e;
      aux->seg = l->pdi;
      aux->ant = l->pdi->ant;
      l->pdi->ant = aux;
      aux->ant->seg = aux;
    }
  }
}

void LLISTABID_insereixdarrera(llistaBID *l, element e){
  Node *aux;
  if(l->pdi == l->ult){
    printf("Error\n", );
  }else{
    aux =(Node*) malloc (sizeof(Node));
    if (aux == NULL) {
      printf("Error\n", );
    }else{
      aux->e = e;
      if (l->pdi->seg == NULL) {
        printf("Error\n", );
      }else{
        aux->e = e;
        aux->seg = l->pdi->seg;
        aux->ant = l->pdi;
        l->pdi->seg->ant = aux;
        l->pdi->seg = aux;
      }
    }
  }
}
