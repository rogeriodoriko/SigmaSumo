void controle() {
  acaoInicio();
  
  lerUltrasons();

  if (dist1 <= distMaxima && dist2 <= distMaxima) {
    //verifica se algum ultrassom frontal ve algo
    acaoFrente();
  } else {
    //nemhum tcrt e nenhum ultrasom ve nada
    acaoProcurar();
  }
}
