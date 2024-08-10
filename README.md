# Labyrinthe
Le jeu du Labyrinthe de 15 × 15 cases :
Pour l’utilisateur, il est indispensable d’avoir un fichier txt nommé « Labyrinthe.txt » où sont stockées les valeurs 0, 1 et 2.
0 - les cases vides où l’utilisateur peut déplacer
1 - les murs sur lesquels il est impossible d’effectuer le mouvement
2 - la sortie du labyrinthe, dès que l’utilisateur est à la case sous le numéro 2, il gagne la partie

![image](https://github.com/user-attachments/assets/4770d551-36b5-4ecf-b56a-6ccdc050ab2f)

Exemple de fichier txt:

![image](https://github.com/user-attachments/assets/e27cf940-6aa5-4d10-9947-e32be1e32625)

L’interface graphique contient aussi une carte sur laquelle l’utilisateur peut voir sa position approximative dans un labyrinthe.

![image](https://github.com/user-attachments/assets/2d15beb8-60fe-431a-a8aa-d40388b65eea)


Initialement, on se place aléatoirement à la case vide (élément 0 de la matrice), après l’utilisateur peut se déplacer en appuyant sur les flèches. Il a au début de jeux 40 pas pour sortir du labyrinthe. Si l’utilisateur se déplace vers les murs, le programme va affiche que c’est impossible et le pas, dans ce cas, ne se perd pas. Le jeu se termine lorsqu’il n’y a plus de pas ou si l’utilisateur trouve la sortie (element 2 de la matrice). Il y a toujours la possibilité de recommencer la partie en appuyant sur R.

Dès que la partie se termine, les pas restants sont enregistrés dans le fichier score.txt si l’utilisateur a battu son record, sinon, on garde le score précédent.

![image](https://github.com/user-attachments/assets/581355f4-5204-41f2-a6c8-357a69cdb50d)

