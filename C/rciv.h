unsigned char key[256]; 
unsigned char s[256];
unsigned char *chiper;
unsigned int i, j, tamanhoKey, tamanhoPlainText;

void troca(unsigned char *s, unsigned short *i, unsigned short *j)
{
  s[*i] = s[*i] + s[*j];
  s[*j] = s[*i] - s[*j];
  s[*i] = s[*i] - s[*j];
}

void ksa(unsigned short *i, unsigned short *j, unsigned short *tamanhoKey)
{
  for (*i = 0; *i < 256; (*i)++)
  {
    s[*i] = *i;
  } 
  
  *j = 0;
 
  for (*i = 0; *i < 256; (*i)++)
  {
    *j = (*j + s[*i] + key[*i % *tamanhoKey]) % 256;
    troca(s, i, j);
  }

 *i = 0;
 *j = 0;
}

void prga (unsigned char *plain, unsigned short *i, unsigned short *j, unsigned short *tamanhoPlainText)
{ 
  unsigned int aux;
  unsigned char result[*tamanhoPlainText-1];

  for (aux = 0; aux < *tamanhoPlainText; aux++)
  {
    *i = (*i + 1) % 256;
    *j = (*j + s[*i]) % 256;
    troca(s, i, j);
    result[aux] = (s[(s[*i] + s[*j]) % 256]) ^ *(plain + aux);
  }

  chiper = (unsigned char*) calloc((*tamanhoPlainText - 1), (sizeof(unsigned char)));
  strcpy(chiper, result);
}

unsigned char *chiperText(unsigned char *plain, unsigned char *key1, unsigned short *i, unsigned short *j, unsigned short *tamanhoKey, unsigned short *tamanhoPlainText)
{
  int cont = 0;

  while(cont < 256){
    key[cont] = *(key1 + cont);
    cont++;
  }

  ksa(i, j, tamanhoKey);
  prga(plain, i, j, tamanhoPlainText);

  return(chiper);
}

unsigned char *plainText(unsigned char *plain, unsigned char *key1, unsigned short *i, unsigned short *j, unsigned short *tamanhoKey, unsigned short *tamanhoPlainText)
{
  int cont = 0;

  while(cont < 256){
    key[cont] = *(key1 + cont);
    cont++;
  }

  ksa(i, j, tamanhoKey);
  prga(plain, i, j, tamanhoPlainText);

  return(chiper);
}


short *menu()
{
  short *r = (short *) calloc(1, sizeof(short*));

  puts("#####################################################################");
  puts("################### Criptografia RC4 + MFC + RSA  ###################");
  puts("#####################################################################");
  puts("################### Escolha uma das opcoes abaixo ###################");
  puts("#####################################################################");
  puts("################### \t0 - Sair\t\t  ###################");
  puts("################### \t1 - Criptografar\t  ###################");
  puts("################### \t2 - Descriptografar\t  ###################");
  puts("################### \t3 - Apagar Arquivos\t  ###################");
  puts("#####################################################################");
  printf("\t\t\t  Opcao: ");
  scanf("%d", &r);
  puts("#####################################################################");
  fflush(stdin);

  return r;
  free(r);
}