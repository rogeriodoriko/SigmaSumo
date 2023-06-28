//função que le os sensores ultrassonicos é utilizada pela função que filtra essa leitura
float ultrasom(int pino_echo, int pino_trigger)
{
  uint32_t tstart, tstop;
  float distancia;
  tstart = micros();
  digitalWrite(pino_trigger, LOW);
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);
  while (!digitalRead(pino_echo))
  {
    if ((micros() - tstart) > 6500)
      return 110;
  }
  tstart = micros();
  while (digitalRead(pino_echo))
  {
    if ((micros() - tstart) > 6500)
      return 110;
  }
  tstop = micros();
  distancia = 0.0170145 * (tstop - tstart);
  return distancia;
}

//função que filtra a leitura dos ultrassonicos, le 4 vezes exclui a maior e a menor e faz a media das duas que sobraram
float leituraUltrasom(int pino_echo, int pino_trigger)
{
  //  Serial.println("Novo");
  float v[4], med = 0;
  v[0] = ultrasom(pino_echo, pino_trigger);
  delay(2);
  v[1] = ultrasom(pino_echo, pino_trigger);
  delay(2);
  v[2] = ultrasom(pino_echo, pino_trigger);
  delay(2);
  v[3] = ultrasom(pino_echo, pino_trigger);

  //  Serial.println(v[0]);
  //  Serial.println(v[1]);
  //  Serial.println(v[2]);
  //  Serial.println(v[3]);
  //  delay(200);

  float maximo = max(v[0], v[1]);
  maximo = max(maximo, v[2]);
  maximo = max(maximo, v[3]);

  //  Serial.println(maximo);
  float minimo = min(v[0], v[1]);
  minimo = min(minimo, v[2]);
  minimo = min(minimo, v[3]);
  //  Serial.println(minimo);
  med = v[0] + v[1] + v[2] + v[3] - maximo - minimo;
  return med / 2;
}

void lerUltrasons() {
  dist1 = leituraUltrasom(ECHO1, TRIG1);//Frente Esquerda
  dist2 = leituraUltrasom(ECHO2, TRIG2);//Frente Direita
}
