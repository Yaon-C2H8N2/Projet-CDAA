DROP TABLE contacts;
DROP TABLE interactions;

CREATE TABLE contacts
(
    id           INTEGER PRIMARY KEY,
    nom          VARCHAR NOT NULL,
    prenom       VARCHAR NOT NULL,
    mail         VARCHAR NOT NULL,
    entreprise   VARCHAR,
    cheminPhoto  VARCHAR NOT NULL,
    tel          VARCHAR NOT NULL,
    dateCreation DATE    NOT NULL
);

CREATE TABLE interactions
(
    id              INTEGER PRIMARY KEY,
    idContact       INTEGER NOT NULL,
    contenu         VARCHAR NOT NULL,
    dateInteraction DATE    NOT NULL,
    CONSTRAINT fk_idContact FOREIGN KEY (idContact) REFERENCES contacts (id) ON DELETE CASCADE
);
