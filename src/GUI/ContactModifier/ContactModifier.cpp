#include <QFileDialog>
#include "ContactModifier.h"

/**
 * Constructeur de la classe ContactModifier.
 * @param parent
 * Un pointeur vers la QDialog dans laquelle l'UI est affiché.
 */
ContactModifier::ContactModifier(QDialog *parent) {
    this->parent = parent;
    this->ui.setupUi(this);
    QObject::connect(this->ui.buttonBox, SIGNAL(accepted()), this, SLOT(validateChanges()));
    QObject::connect(this->ui.photoPathEdit, SIGNAL(clicked(bool)), this, SLOT(onPicturePushButtonClicked()));
}

/**
 * Fonction permettant de définir le Contact à modifier.
 * @param contact
 * Une instance de Contact.
 */
void ContactModifier::setContact(Contact contact) {
    this->contact = contact;
    this->ui.firstNameEdit->setText(QString::fromStdString(contact.getPrenom()));
    this->ui.lastNameEdit->setText(QString::fromStdString(contact.getNom()));
    this->ui.mailEdit->setText(QString::fromStdString(contact.getMail()));
    this->ui.phoneNumberEdit->setText(QString::fromStdString(contact.getTel()));
    this->ui.companyNameEdit->setText(QString::fromStdString(contact.getEntreprise()));
    this->pictureFilePath = contact.getCheminPhoto();
    QIcon icon(QString::fromStdString(this->pictureFilePath));
    this->ui.photoPathEdit->setIcon(icon);
    this->ui.photoPathEdit->setText("");
    this->ui.photoPathEdit->setIconSize(QSize(150,150));
}

/**
 * Fonction permettant d'accéder au contact contenu par cette classe.
 * @return
 * Une instance de Contact.
 */
Contact ContactModifier::getContact() {
    return this->contact;
}

/**
 * Slot générant une fenêtre de dialogue permettant de sélectionner un fichier à associer au contact que l'on souhaite créer.
 */
void ContactModifier::onPicturePushButtonClicked() {
    QFileDialog dialog(nullptr);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setReadOnly(true);
    dialog.setFilter(QDir::Files);
    dialog.setNameFilter("Images (*.png *.jpg)");
    if(dialog.exec()){
        this->pictureFilePath = dialog.selectedFiles().value(0).toStdString();
        QIcon icon(dialog.selectedFiles().value(0));
        this->ui.photoPathEdit->setIcon(icon);
        this->ui.photoPathEdit->setText("");
        this->ui.photoPathEdit->setIconSize(QSize(150,150));
    }
}

/**
 * Slot déclenché lorsque l'utilisateur valide la modification du contact.
 */
void ContactModifier::validateChanges() {
    this->contact.setPrenom(this->ui.firstNameEdit->text().toStdString());
    this->contact.setNom(this->ui.lastNameEdit->text().toStdString());
    this->contact.setMail(this->ui.mailEdit->text().toStdString());
    this->contact.setTel(this->ui.phoneNumberEdit->text().toStdString());
    this->contact.setEntreprise(this->ui.companyNameEdit->text().toStdString());
    this->contact.setCheminPhoto(this->pictureFilePath);
}
