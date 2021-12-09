#include "Sender.hh"

using namespace std;

int Sender::Send(const char *sMesg)
{
  ssize_t  IlWyslanych;
  ssize_t  IlDoWyslania = (ssize_t) strlen(sMesg);

  while ((IlWyslanych = write(_Socket,sMesg,IlDoWyslania)) > 0) {
    IlDoWyslania -= IlWyslanych;
    sMesg += IlWyslanych;
  }
  if (IlWyslanych < 0) {
    cerr << "*** Blad przeslania napisu." << endl;
  }
  return 0;
}

void Sender::Watching_and_Sending() {
    while (ShouldCountinueLooping()) {
        if (!_pScn->IsChanged())  { usleep(10000); continue; }
        _pScn->LockAccess();
        for (const auto &rObj : _pScn->GetMobileObjects()) {
            cout << rObj.second->Message();
             Send(rObj.second->Message().c_str());
        }
        _pScn->CancelChange();
        _pScn->UnlockAccess();
    }
}

void Fun_CommunicationThread(Sender  *pSender) {
  pSender->Watching_and_Sending();
}

bool OpenConnection(int &rSocket)
{
  struct sockaddr_in  DaneAdSerw;

  bzero((char *)&DaneAdSerw,sizeof(DaneAdSerw));

  DaneAdSerw.sin_family = AF_INET;
  DaneAdSerw.sin_addr.s_addr = inet_addr(IP);
  cout << "lacze z " << IP << endl;
  DaneAdSerw.sin_port = htons(PORT);


  rSocket = socket(AF_INET,SOCK_STREAM,0);

  if (rSocket < 0) {
     cerr << "*** Blad otwarcia gniazda." << endl;
     return false;
  }

  if (connect(rSocket,(struct sockaddr*)&DaneAdSerw,sizeof(DaneAdSerw)) < 0)
   {
     cerr << "*** Brak mozliwosci polaczenia do portu: " << PORT << endl;
     return false;
   }
  return true;
}

bool ChangeState(Scene &Scn) //GeomObject *pObj, AccessControl  *pAccCtrl)
{
    /*
  bool Changed;

  while (true) {
    Scn.LockAccess(); // Zamykamy dostęp do sceny, gdy wykonujemy
                            // modyfikacje na obiekcie.
    for (GeomObject &rObj : Scn._Container4Objects) {
       if (!(Changed = rObj.IncStateIndex())) { Scn.UnlockAccess();  return false; }
    }
    Scn.MarkChange();
    Scn.UnlockAccess();
    usleep(300000);
  }
  */
  return true;
}

