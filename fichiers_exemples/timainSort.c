int main()
{
  srand(time(NULL));
  const int TAILLE = 10;
  int tab [TAILLE];
  for (int i = 0; i < 50; i++)
  {
    for (int i = 0; i < TAILLE; i++)
      tab[i] = rand() % TAILLE;
      switch (i % 3){
        case 0 : triABulle(tab, TAILLE); break;
        case 1 : triInsertion(tab,TAILLE); break;
        case 2 : triSelection(tab,TAILLE); break;
      }
      imprimerTableau(tab,TAILLE);
    }
}
