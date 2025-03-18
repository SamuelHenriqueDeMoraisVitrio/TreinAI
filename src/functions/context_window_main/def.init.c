//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


void TreinAi_init_window_context(TreinAi_Arguments *args){

  OpenAiInterface *self = newOpenAiInterface(args->url_api, args->key, args->model_name);

  TreinAi_add_messages_system_initial(self);

  size_t size_buffer = TREINAI_BUFFER_SIZE - 1;
  char *buffer = BearsslHttps_allocate(TREINAI_BUFFER_SIZE);
  short response_buffer_input = TREINAI_CHAT_RESPONSE_BUFFER_OK;
  
  while(response_buffer_input == TREINAI_CHAT_RESPONSE_BUFFER_OK){
    
    response_buffer_input = TreinAi_init_chat(buffer, size_buffer, "> ");

    if(response_buffer_input != TREINAI_CHAT_RESPONSE_BUFFER_OK){
      const char *message = TreinAi_chat_returned_handling(response_buffer_input);
      if(message){
        printf("\n\tErro:. %s\n", message);
      }
      break;
    }

    OpenAiResponse *response = OpenAiInterface_make_question_finish_reason_treated(self);
    if(OpenAiResponse_error(response)){
      printf("%sError: %s%s\n", RED, OpenAiResponse_get_error_message(response), RESET);
      break;
    }

    printf("\n\tchat: %s\n", OpenAiResponse_get_content_str(response, 0));
  }

  printf("\n\tEND\n");

}


