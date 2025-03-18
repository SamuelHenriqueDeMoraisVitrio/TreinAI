//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end


void TreinAi_add_messages_system_initial(OpenAiInterface *self){

  OpenAiInterface_add_system_prompt(self, TREINAI_SYSTEM_MESSAGES_YOUR_ARE_AGENT);
  OpenAiInterface_add_system_prompt(self, TREINAI_SYSTEM_MESSAGES_YOUR_FUNCTION);

}



