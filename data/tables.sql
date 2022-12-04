DROP TABLE contacts;
DROP TABLE interactions;
DROP TABLE taches;

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
    id              INTEGER NOT NULL,
    idContact       INTEGER NOT NULL,
    contenu         VARCHAR NOT NULL,
    dateInteraction DATE    NOT NULL,
    CONSTRAINT fk_idContact FOREIGN KEY (idContact) REFERENCES contacts (id) ON DELETE CASCADE,
    CONSTRAINT pk_idInteraction PRIMARY KEY (id, idContact)
);

CREATE TABLE taches
(
    idTache       INTEGER PRIMARY KEY,
    idInteraction INTEGER NOT NULL,
    idContact     INTEGER NOT NULL,
    contenu       VARCHAR NOT NULL,
    dateTache     DATE    NOT NULL,
    CONSTRAINT fk_idInteraction FOREIGN KEY (idInteraction, idContact) REFERENCES interactions (id, idContact) ON DELETE CASCADE
);