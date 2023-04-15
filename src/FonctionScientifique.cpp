#include "FonctionScientifique.hpp"
#include <cstdlib>
/**
 * La classe qui définie le plateau de jeu et les fonctions permettant d'interagir avec.
 * @author Mathis Roptin, Alexander Camatchy, Victoire Dane Moukoko Ndongo, Felix Senechal, Université de Caen Normandie
 */
FonctionScientifique::FonctionScientifique(int nbtest, int nbJoueur, int nbEquipe, int* algo, int* repartitionEquipe){
    this->nbtest=nbtest;
    this->nbJoueur=nbJoueur;
    this->nbEquipe=nbEquipe;
    this->algo=algo;
    this->repartitionEquipe=repartitionEquipe;
}
int** FonctionScientifique::tabVictoire(int profMin, int profMax, int taille){
    int tailleTab = profMax-profMin;
    int** tab = new int*[tailleTab];
    for(int i=0;i<tailleTab; i++){
        tab[i]= new int[nbEquipe];
    }
    for(int prof=profMin; prof<profMax; prof++){
        int algos[nbJoueur];
        for(int i = 0; i<nbEquipe*2; i+=2) {
            //algos : l'algo(algo), profondeur, nbequipier
            algos[i] = algo[i-i/2];
            if(i==0){
                algos[i+1] = prof;
            }
            else {
                algos[i+1] = 2;
            }
        }
        for(int i=0; i < nbEquipe; i++) {
            tab[prof-profMin][i] = 0;
        }
        for(int j = 0; j<nbtest;j++){
            // usleep(1000000); // on a plus besoin de sleep parce qu'on randomise plus avec time(null) mais avec getpid()
            Plateau *plateau = new Plateau(taille, nbJoueur, algos);
            while(!plateau->isOver()){
                plateau->play();
            }
            if (plateau->getNbJoueursVivant()>0){
                int winner = plateau->getWinner()[0]-1;
                tab[prof-profMin][winner] +=1;
            }
        }
    }

    return tab;
}
int** FonctionScientifique::tabVictoireNbJoueur(int JoueurMax, int taille){
    int tailleTab = JoueurMax;
    int** tab = new int*[tailleTab];
    for(int i=0;i<tailleTab; i++){
        tab[i]= new int[1];
    }
    for(int nbJ=2; nbJ<JoueurMax; nbJ++){
        int algos[nbJ];
        for(int i = 0; i<nbJ*2; i+=2) {
            //algos : l'algo(algo), profondeur, nbequipier
            algos[i] = algo[0];
            algos[i+1] = 4;
        }
        tab[nbJ-2][0] = 0;
        for(int j = 0; j<nbtest;j++){
            // usleep(1000000); // on a plus besoin de sleep parce qu'on randomise plus avec time(null) mais avec getpid()
            cout << "test" <<endl;
            Plateau *plateau = new Plateau(taille, nbJ, algos);
            cout << "test2" <<endl;
            while(!plateau->isOver()){
                plateau->play();
            }
            cout << "test3" <<endl;
            if (plateau->getNbJoueursVivant()>0){
                int winner = plateau->getWinner()[0]-1;
                if(winner==0){
                    tab[nbJ-2][winner] +=1;
                }
                
            }
        }
        cout << tab[nbJ-2][0] <<endl;
        cout << "fin" <<endl;
    }
    return tab;
}
string FonctionScientifique::tabToCSV(int** tab, int nbJoueur, int min, int taille) {
    // Obtenir l'heure actuelle
    time_t maintenant = time(0);
    tm *ltm = localtime(&maintenant);

    // Créer une chaîne d'horodatage avec la date, l'heure et la minute
    stringstream horodatage;
    horodatage << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon
              << "-" << ltm->tm_mday << "_"
              << ltm->tm_hour << "-" << ltm->tm_min;
    // Choisir le format de fichier .csv
    string extensionFichier = ".csv";
    // Créer le nom du fichier
    string nomFichier = "src/assets/test/victoire_" + horodatage.str() + extensionFichier;
    // Ouvrir le fichier et écrire les données du tab
    ofstream fichierSortie;
    fichierSortie.open (nomFichier);
    if (fichierSortie.is_open()) {
        for (int i =0; i<taille-min; i++) {
            fichierSortie << i+1+min;
            for (int j = 0; j < nbJoueur; j++) {
                int v = tab[i][j];
                fichierSortie << ", " << v;
            }
            fichierSortie << endl;
        }
        fichierSortie.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier pour l'écriture." << endl;
    }
    return nomFichier;
}

int FonctionScientifique::VictoireTaille(int profMax, int tailleMin, int tailleMax){
    int*** tab;
    tab = new int**[tailleMax-tailleMin];
    for(int taille=tailleMin; taille<=tailleMax; taille++){
        tab[taille-tailleMin] = tabVictoire(0, profMax, taille);
    }
    return 0;
}

int FonctionScientifique::PointCroisement(int j, int** tab, int size){
    for(int i=0; i<size; i++){
        for(int t=0; t<nbEquipe; i++){
            if(tab[i][t]>=tab[i][j]){
                break;
            }
            return i;
        }
    }
    return -1;
}

int* FonctionScientifique::getProfondeurDifficille(int j, int*** tab, int nbIteration, int size){
    int* result = new int[2];
    result[0]=0;
    result[1]=0;
    for(int i=0; i<nbIteration; i++){
        int p = PointCroisement(j, tab[i], size);
        if(result[0]<p){
            result[0]=p;
            result[1]=i+3;
        }
    }
    return result;
}

int* FonctionScientifique::getProfondeurFacille(int j, int*** tab, int nbIteration, int size){
    int* result = new int[2];
    result[0]=100000;
    result[1]=0;
    for(int i=0; i<nbIteration; i++){
        int p = PointCroisement(j, tab[i], size);
        if(result[0]>p){
            result[0]=p;
            result[1]=i+3;
        }
    }
    return result;
}

int FonctionScientifique::MoyenneProfondeur(int j, int*** tab, int nbIteration, int size){
    int result = 0;
    for(int i=0; i<nbIteration; i++){
        int p = PointCroisement(j, tab[i], size);
        result+=p;
    }
    return result/size;
}

 void FonctionScientifique::showGraph(int taille, string pathfile){
    string gnuinstruction = "src/assets/instruction.txt";
    string gnupath = "src/assets/result/";

    ofstream myfile;

    myfile.open (gnuinstruction);
    if (myfile.is_open()) {
        myfile << "set grid; \n";
        myfile << "set xrange[-1:"+ to_string(taille) +"]; \n";
        myfile << "set yrange[0:"+ to_string(nbtest) +"]; \n";
        myfile << "set key title 'Joueur' box; \n";
        myfile << "set origin 0,0; \n";
        myfile << "set terminal png; \n";
        myfile << "set boxwidth 0.6 relative; \n";
        myfile << "set style data histograms; \n";
        myfile << "set style histogram cluster gap 2; \n";
        myfile << "set style fill solid 1 border lt -1; \n";
        myfile << "set title 'nombre de victoire par Joueur avec variation de la profondeur du joueur 0' \n";
        myfile << "set xlabel 'profondeur'; \n";
        myfile << "set ylabel 'nombre Victoire'; \n";
        myfile << "set output '"+gnupath+"graph.png'; \n";
        string color[7] = {"red", "blue", "green", "black", "brown", "orange", "yellow"};
        myfile << "plot '" + pathfile+ "' u " + to_string(2) + ":xtic(1) title 'Joueur " + to_string(0) + "' linecolor '"+ color[0] +"'";
        for(int i=1; i<nbEquipe; i++){
            myfile << ", '" + pathfile+ "' u " + to_string(i+2) + ":xtic(1) title 'Joueur " + to_string(i) + "' linecolor '"+ color[i] +"'";
            //myfile << ", '" + pathfile+ "' u 1:" + to_string(i+2) + " title 'equipe " + to_string(i) + "' w lp lt rgb '"+ color[i] +"' lw 2 axes x1y1";
        }
        myfile << "; \n";
        myfile.close();
        const char* commande = "gnuplot -persist src/assets/instruction.txt";
        system(commande);
    }
    else {
        cerr << "Impossible d'ouvrir le fichier pour l'écriture." << endl;
    }
 }

  void FonctionScientifique::showGraphBis(int taille, string pathfile){
    string gnuinstruction = "src/assets/instruction.txt";
    string gnupath = "src/assets/result/";

    ofstream myfile;

    myfile.open (gnuinstruction);
    if (myfile.is_open()) {
        myfile << "set grid; \n";
        myfile << "set xrange[-1:"+ to_string(taille) +"]; \n";
        myfile << "set yrange[0:"+ to_string(nbtest) +"]; \n";
        myfile << "set key title 'Joueur' box; \n";
        myfile << "set origin 0,0; \n";
        myfile << "set terminal png; \n";
        myfile << "set boxwidth 0.6 relative; \n";
        myfile << "set style data histograms; \n";
        myfile << "set style histogram cluster gap 2; \n";
        myfile << "set style fill solid 1 border lt -1; \n";
        myfile << "set title 'nombre de victoire par Joueur avec des algorithme différent' \n";
        myfile << "set xlabel 'profondeur du joueur 0'; \n";
        myfile << "set ylabel 'nombre Victoire'; \n";
        myfile << "set output '"+gnupath+"graph.png'; \n";
        string color[7] = {"red", "blue", "green", "black", "brown", "orange", "yellow"};
        myfile << "plot '" + pathfile+ "' u " + to_string(2) + ":xtic(1) title 'Joueur Maxn' linecolor '"+ color[0] +"'";
        for(int i=1; i<nbEquipe; i++){
            myfile << ", '" + pathfile+ "' u " + to_string(i+2) + ":xtic(1) title 'Joueur Paranoid' linecolor '"+ color[i] +"'";
        }
        myfile << "; \n";
        myfile.close();
        const char* commande = "gnuplot -persist src/assets/instruction.txt";
        system(commande);
    }
    else {
        cerr << "Impossible d'ouvrir le fichier pour l'écriture." << endl;
    }
 }