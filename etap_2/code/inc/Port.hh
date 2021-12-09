#ifndef PORT_HH
#define PORT_HH

/*!
 * \brief Port poprzez który realizowana jest komunikacja z klientem
 *
 * Porzez ten port realizowana jest komunikacja z zewnętrzną
 * aplikacją klienta.
 */
#define PORT  6217

/*!
 * \brief Adres IP z którym łączy się klient.
 *
 * Adres IP podawany jako tablica znaków. Po połączeniu się do adresu IP
 * następuje komunikacja z serwerem.
 * 127.0.0.1 -- domyślny adres komputera na którym działa klient,
 * 156.17.9.7 -- adres Panaminta
 */
//#define IP "156.17.9.7"
#define IP "127.0.0.1"

#endif
