INSERT INTO contacts
VALUES (null, 'Rouze', 'Fitz', 'FitzRouze@jourrapide.com', 'Xray Eye & Vision Clinics',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '01 79 77 78 89', datetime());

INSERT INTO contacts
VALUES (null, 'Vadnais', 'Étienne', 'EtienneVadnais@rhyta.com', 'Karl Shoes',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '05 90 27 87 31', datetime());

INSERT INTO contacts
VALUES (null, 'Lamontagne', 'Laverne', 'LaverneLamontagne@teleworm.us', 'Sunburst Garden Management',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '02 27 18 60 28', datetime());

INSERT INTO contacts
VALUES (null, 'Lamour', 'Andrée', 'AndreeLamour@armyspy.com', 'Mostow Co.',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '04 24 23 24 37', datetime());

INSERT INTO contacts
VALUES (null, 'Grenier', 'Ignace', 'IgnaceGrenier@dayrep.com', 'Your Choices',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '01 40 06 43 78', datetime());

INSERT INTO contacts
VALUES (null, 'Poirier', 'Aubin', 'AubinPoirier@dayrep.com', 'Albers Super Markets',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '04 58 81 47 97', datetime());

INSERT INTO contacts
VALUES (null, 'Ruest', 'Porter', 'PorterRuest@dayrep.com', 'Sunburst Garden Management',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '01 75 58 08 67', datetime());

INSERT INTO contacts
VALUES (null, 'Beaulieu', 'Denise', 'DeniseBeaulieu@armyspy.com', 'Burstein-Applebee',
        '/home/yaon/Documents/Projet-CDAA/data/photo/default.png', '03 02 92 47 93', datetime());

INSERT INTO interactions
VALUES (1, 1, 'Appel client', datetime());

INSERT INTO interactions
VALUES (2, 1, 'Appel client @todo rappeler client @date 15/12/2022', datetime());

INSERT INTO interactions
VALUES (1, 2, 'Appel client', datetime());

INSERT INTO interactions
VALUES (1, 5, 'Appel client @todo rappeler client', datetime());

INSERT INTO taches
VALUES (null, 2, 1, 'rappeler client', '2022-12-15');

INSERT INTO taches
VALUES (null, 1, 5, 'rappeler client', date());