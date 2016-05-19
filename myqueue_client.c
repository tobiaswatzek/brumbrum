#include "myqueue.h"
#include "autobahn.h"
#include "rlutil.h"

int main(int argc, char* argv[]){
   navigation msg;	/* Buffer fuer Message */
   int msgid = -1;	/* Message Queue ID */

   /* Argument Handling */
   if (argc!=2)
   {
      fprintf(stderr,"Usage: %s <Message>\n",argv[0]);
      return EXIT_FAILURE;
   }

   /* Message Queue oeffnen von msgget */
   if( (msgid = msgget(KEY,PERM))==-1 ){
      /* error handling */
      fprintf(stderr,"%s: Can't access message queue\n",argv[0]);
      return EXIT_FAILURE;
   }

   /* Nachricht verschicken */
   msg.client_id = 'A';
   msg.direction = 'N';
   //strncpy(msg.mText,argv[1],MAX_DATA);
   if (msgsnd(msgid,&msg,sizeof(msg), 0) == -1)
   {
         /* error handling */
         fprintf(stderr,"%s: Can't send message\n",argv[0]);
         return EXIT_FAILURE;
   }
   printf("Message sent: %s\n",msg.client_id);
   msgctl(4224124242421, IPC_RMID, NULL);
   return EXIT_SUCCESS;
}
