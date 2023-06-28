void acaoInicio() {
  if (flag == 0) {
    while (digitalRead(PUSHB));
    delay(5000);
    flag = 1;
    irFrente();
    delay(1200);
  }
}

void acaoFrente() {
  if (dist1 <= distMaxima && dist2 <= distMaxima) {
    //os dois ultrassons veem
    irFrente();
  } else if (dist1 <= distMaxima && dist2 >= distMaxima) {
    //so o ultrassom da esquerda ve
    irEsquerda(0);
  } else if (dist1 >= distMaxima && dist2 <= distMaxima) {
    //so o ultrassom da direita ve
    irDireita(0);
  }
}

void acaoProcurar() {
  girar();
}
