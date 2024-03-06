

mysql> select * from chevale;
+------------+----------+---------+-----------------+---------+-------------+---------+---------+
| id_chevale | nom_chev | couleur | numero_tatouage | id_race | id_personne | id_mere | id_pere |
+------------+----------+---------+-----------------+---------+-------------+---------+---------+
|          1 | Alaska   | Rouge   |               1 |       1 |           1 |       1 |       1 |
|          2 | Shadow   | Black   |               2 |       2 |           2 |       2 |       2 |
|          3 | Tornado  | Orange  |               3 |       3 |           3 |       3 |       3 |
|          4 | Thunder  | Black   |               4 |       4 |           4 |       4 |       4 |
|          5 | Beauty   | Yellow  |               5 |       5 |           5 |       5 |       5 |
|          6 | Star     | white   |               6 |       6 |           6 |       6 |       6 |
+------------+----------+---------+-----------------+---------+-------------+---------+---------+
6 rows in set (0.00 sec)

mysql> select * from concours;
+------------------------+---------------------+----------------+---------------------+
| nom_concours           | lieu                | annee_concours | nombre_Participants |
+------------------------+---------------------+----------------+---------------------+
| Coupe des Cavaliers    | Medina Marrakech    | 2019-10-31     |                 400 |
| Grand prix de dressage | Massira 1 Marrakech | 2019-01-01     |                 500 |
| Les chevaliers         | Azli Marrakech      | 2024-03-12     |                 300 |
+------------------------+---------------------+----------------+---------------------+
3 rows in set (0.00 sec)

mysql> select * from personne;
+-------------+---------+------------+---------------+-------------+--------------+------------+
| id_personne | nom_per | prenom_per | telephone     | adresse_per | fonction     | id_persupe |
+-------------+---------+------------+---------------+-------------+--------------+------------+
|           1 | salah   | Miechel    | +212612324568 | Marrakech   | eleveur      |          1 |
|           2 | Dupont  | Marie      | +212512642479 | Casa        | Directeur    |       NULL |
|           3 | Jean    | Dupont     | +21323232323  | Paris       | eleveur      |          2 |
|           4 | Ahmed   | El-mansori | +21211111111  | Rabat       | eleveur      |          3 |
|           5 | Sophia  | Pastel     | +2023232323   | Monaco      | proprietaire |          4 |
|           6 | Luca    | Rossi      | +123232323232 | America     | Comptable    |          5 |
+-------------+---------+------------+---------------+-------------+--------------+------------+
6 rows in set (0.00 sec)

mysql> select * from race;
+---------+------------+-------------+----------+
| id_race | poids_type | taille_type | nom_race |
+---------+------------+-------------+----------+
|       1 |      120.3 |         2.5 | Arabian  |
|       2 |        100 |           2 | Frison   |
|       3 |        110 |           3 | Arabian  |
|       4 |        120 |         2.6 | Arabian  |
|       5 |        115 |         1.9 | Arabian  |
|       6 |        120 |         2.4 | Arabian  |
+---------+------------+-------------+----------+
6 rows in set (0.00 sec)

mysql> select * from proprietaire;
+-------------+------------+------------+------------+
| id_personne | id_Chevale | prix_achat | date_achat |
+-------------+------------+------------+------------+
|           1 |          1 |    3000000 | 2024-03-06 |
|           2 |          2 |    3500000 | 2023-01-01 |
|           3 |          3 |    2500000 | 2022-01-19 |
|           4 |          4 |    2000000 | 2024-01-01 |
|           5 |          5 |    4000000 | 2021-11-09 |
|           6 |          6 |    3000000 | 2022-12-11 |
+-------------+------------+------------+------------+
6 rows in set (0.00 sec)

mysql> select * from participant;
+----------------+----------------+------------+-------+
| nom_concours   | annee_concours | id_chevale | ranke |
+----------------+----------------+------------+-------+
| Les chevaliers | 2024-03-12     |          1 |     1 |
| Les chevaliers | 2024-03-12     |          2 |     2 |
| Les chevaliers | 2024-03-12     |          3 |     3 |
| Les chevaliers | 2024-03-12     |          4 |     4 |
| Les chevaliers | 2024-03-12     |          5 |    10 |
| Les chevaliers | 2024-03-12     |          6 |     7 |
+----------------+----------------+------------+-------+
6 rows in set (0.00 sec)

mysql> select * from croissance;
+---------+------+------------+-------------+------------+
| id_croi | mois | poids_croi | taille_croi | id_chevale |
+---------+------+------------+-------------+------------+
|       1 |   11 |      125.5 |         2.9 |          1 |
|       2 |   10 |        110 |         2.5 |          2 |
|       3 |    8 |        110 |         3.2 |          3 |
|       4 |    5 |        124 |           3 |          4 |
|       5 |   12 |        125 |         2.7 |          5 |
|       6 |   12 |        140 |         3.5 |          6 |
+---------+------+------------+-------------+------------+
6 rows in set (0.00 sec)

mysql> select id_chevale,nom_chev,couleur,nom_race from chevale  join race on chevale.id_race=race.id_race where nom_race='Arabian' order by nom_chev desc;
+------------+----------+---------+----------+
| id_chevale | nom_chev | couleur | nom_race |
+------------+----------+---------+----------+
|          3 | Tornado  | Orange  | Arabian  |
|          4 | Thunder  | Black   | Arabian  |
|          6 | Star     | white   | Arabian  |
|          5 | Beauty   | Yellow  | Arabian  |
|          1 | Alaska   | Rouge   | Arabian  |
+------------+----------+---------+----------+
5 rows in set (0.00 sec)

mysql> select id_chevale,nom_chev,couleur,nom_race,poids_type,taille_type from chevale  join race on chevale.id_race=race.id_race where nom_race='Arabian';
+------------+----------+---------+----------+------------+-------------+
| id_chevale | nom_chev | couleur | nom_race | poids_type | taille_type |
+------------+----------+---------+----------+------------+-------------+
|          1 | Alaska   | Rouge   | Arabian  |      120.3 |         2.5 |
|          3 | Tornado  | Orange  | Arabian  |        110 |           3 |
|          4 | Thunder  | Black   | Arabian  |        120 |         2.6 |
|          5 | Beauty   | Yellow  | Arabian  |        115 |         1.9 |
|          6 | Star     | white   | Arabian  |        120 |         2.4 |
+------------+----------+---------+----------+------------+-------------+
5 rows in set (0.00 sec)

mysql> select * from proprietaire;
+-------------+------------+------------+------------+
| id_personne | id_Chevale | prix_achat | date_achat |
+-------------+------------+------------+------------+
|           1 |          1 |    3000000 | 2024-03-06 |
|           2 |          2 |    3500000 | 2023-01-01 |
|           3 |          3 |    2500000 | 2022-01-19 |
|           4 |          4 |    2000000 | 2024-01-01 |
|           5 |          5 |    4000000 | 2021-11-09 |
|           6 |          6 |    3000000 | 2022-12-11 |
+-------------+------------+------------+------------+
6 rows in set (0.00 sec)

mysql> select * from personne where id_persupe is null;
+-------------+---------+------------+---------------+-------------+-----------+------------+
| id_personne | nom_per | prenom_per | telephone     | adresse_per | fonction  | id_persupe |
+-------------+---------+------------+---------------+-------------+-----------+------------+
|           2 | Dupont  | Marie      | +212512642479 | Casa        | Directeur |       NULL |
+-------------+---------+------------+---------------+-------------+-----------+------------+
1 row in set (0.00 sec)

mysql> select * from concours where annee_concours between '2019-01-01' and '2019-12-31';
+------------------------+---------------------+----------------+---------------------+
| nom_concours           | lieu                | annee_concours | nombre_Participants |
+------------------------+---------------------+----------------+---------------------+
| Grand prix de dressage | Massira 1 Marrakech | 2019-01-01     |                 500 |
| Coupe des Cavaliers    | Medina Marrakech    | 2019-10-31     |                 400 |
+------------------------+---------------------+----------------+---------------------+
2 rows in set (0.00 sec)
