//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "imports/imports.def.h"
//silver_chain_scope_end

int main(int argc, char *argv[]){

  CArgvParse args = newCArgvParse(argc,argv);
  TreinAi_Arguments *arguments = new_TreinAI_Arguments(&args);
  if(!arguments){
    printf("\n\tArguments provided in error.\n");
    return 1;
  }

  TreinAi_init_window_context(arguments);

  return 0;
}


