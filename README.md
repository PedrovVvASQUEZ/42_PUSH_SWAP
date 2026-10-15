# push_swap

Projet d’algorithmie en C inspiré du sujet **push_swap** de 42. Le programme trie une séquence d’entiers en utilisant deux piles et en produisant une suite d’opérations limitée, avec pour objectif de réduire le nombre de mouvements.

## Principe

Les valeurs sont stockées dans deux piles, **A** et **B**, représentées par des listes doublement chaînées. Le programme commence par placer une partie des valeurs dans B, puis réinsère les éléments dans A dans le bon ordre. Pour chaque réinsertion, il détermine une position cible, estime le coût des rotations nécessaires et choisit le déplacement le moins coûteux. Les rotations communes aux deux piles sont combinées lorsque c’est possible. Les petits cas sont traités séparément, puis le minimum est replacé en tête de A.

Le résultat est une liste d’instructions sur la sortie standard. Une entrée déjà triée ne nécessite aucune instruction.

## Compilation

Le projet se compile avec `make` :

```sh
make
```

Cela construit `push_swap` et sa bibliothèque C locale `pedro_lib/pedro_lib.a`. Le vérificateur bonus se construit séparément :

```sh
make bonus
```

Commandes de nettoyage disponibles : `make clean`, `make fclean` et `make re`.

## Utilisation

Passer les entiers dans un seul argument, séparés par des espaces :

```sh
./push_swap "4 67 3 0 -1"
```

Pour vérifier la suite d’opérations avec le programme bonus :

```sh
ARG="4 67 3 0 -1"
./push_swap "$ARG" | ./checker "$ARG"
```

Le checker lit les opérations depuis l’entrée standard et affiche `OK` si A est triée dans l’ordre croissant et B est vide, `KO` sinon. Une instruction inconnue produit `Error`.

## Opérations disponibles

| Instruction | Effet |
| --- | --- |
| `sa`, `sb`, `ss` | Échange les deux premiers éléments de A, de B, ou des deux piles. |
| `pa`, `pb` | Déplace le sommet d’une pile vers l’autre. |
| `ra`, `rb`, `rr` | Effectue une rotation vers le haut sur A, B, ou les deux piles. |
| `rra`, `rrb`, `rrr` | Effectue une rotation inverse sur A, B, ou les deux piles. |

Les opérations sans suffixe combiné agissent sur une seule pile ; les formes `ss`, `rr` et `rrr` appliquent l’action aux deux piles.

## Entrées et erreurs

Les arguments doivent être des entiers représentables par le type `int`, sans doublons. Une entrée invalide (valeur non numérique, doublon ou dépassement de plage) affiche `Error`.

## Structure du dépôt

- Les fichiers C à la racine contiennent le programme de tri, le traitement des arguments, les opérations sur les piles et la logique de réinsertion.
- `push_swap_bonus/` contient le programme `checker` et ses opérations, qui appliquent les instructions reçues.
- `pedro_lib/` contient la bibliothèque C utilisée par le projet, dont des fonctions de chaînes, d’E/S et `get_next_line`.

## Technologies

- Langage C
- Make
- Bibliothèque standard du projet dans `pedro_lib/`