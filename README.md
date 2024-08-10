# Labyrinthe
Le jeu du Labyrinthe de 15 × 15 cases :
Pour l’utilisateur, il est indispensable d’avoir un fichier txt nommé « Labyrinthe.txt » où sont stockées les valeurs 0, 1 et 2.
0 - les cases vides où l’utilisateur peut déplacer
1 - les murs sur lesquels il est impossible d’effectuer le mouvement
2 - la sortie du labyrinthe, dès que l’utilisateur est à la case sous le numéro 2, il gagne la partie



Exemple de fichier txt:


L’interface graphique contient aussi une carte sur laquelle l’utilisateur peut voir sa position approximative dans un labyrinthe.



Initialement, on se place aléatoirement à la case vide (élément 0 de la matrice), après l’utilisateur peut se déplacer en appuyant sur les flèches. Il a au début de jeux 40 pas pour sortir du labyrinthe. Si l’utilisateur se déplace vers les murs, le programme va affiche que c’est impossible et le pas, dans ce cas, ne se perd pas. Le jeu se termine lorsqu’il n’y a plus de pas ou si l’utilisateur trouve la sortie (element 2 de la matrice). Il y a toujours la possibilité de recommencer la partie en appuyant sur R.

Dès que la partie se termine, les pas restants sont enregistrés dans le fichier score.txt si l’utilisateur a battu son record, sinon, on garde le score précédent.


