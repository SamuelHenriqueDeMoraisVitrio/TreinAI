//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end






short TreinAi_init_chat(char *buffer, size_t size_max_buffer, const char *initial_caracter){

  memset(buffer, 0, size_max_buffer);
  long size_buffer_temp = size_max_buffer + 1;
  char *buffer_temp = BearsslHttps_allocate(size_buffer_temp);
  if(!buffer_temp){
    return TREINAI_CHAT_RESPONSE_ERROR_ALOCATED;
  }
  long size_max = size_max_buffer - 1;
  long size_buffer = 0;

  while(size_max > 0){
    memset(buffer_temp, 0, size_max_buffer + 1);
    if(initial_caracter){
      printf("%s%s%s", BLUE, initial_caracter, RESET);
    }

    if (fgets(buffer_temp, size_max, stdin) != NULL) {
      long temp_size = strlen(buffer_temp);

      if (temp_size > size_max) {
        return TREINAI_CHAT_RESPONSE_BUFFER_BURST;
      }

      long now_temp_size = temp_size - 2;
      if(strcmp(buffer_temp + now_temp_size, "\\\n") == 0){ //compara o final com shift + Enter
        memcpy(buffer + size_buffer, buffer_temp, now_temp_size);
        size_max -= now_temp_size;
        size_buffer += now_temp_size + 1;
        buffer[size_buffer - 1] = '\n';
        continue;
      }

      memcpy(buffer + size_buffer, buffer_temp, temp_size - 1);
      size_max -= temp_size;
      size_buffer += temp_size;
      buffer[size_buffer - 1] = '\0';
      break;
    }

    return TREINAI_CHAT_RESPONSE_INVALID_READ;
  }

  if(size_max <= 0){
    return TREINAI_CHAT_RESPONSE_BUFFER_BURST;
  }

  if(strcmp(buffer, "exit") == 0){
    return TREINAI_CHAT_RESPONSE_EXIT_COMMAND;
  }

  return TREINAI_CHAT_RESPONSE_BUFFER_OK;
}

const char *TreinAi_chat_returned_handling(short response_chat){
  if(!(response_chat < 0)){
    return NULL;
  }
  if(response_chat == TREINAI_CHAT_RESPONSE_BUFFER_BURST){
    return TREINAI_CHAT_RESPONSE_BUFFER_BURST_MESSAGE;
  }
  if(response_chat == TREINAI_CHAT_RESPONSE_INVALID_READ){
    return TREINAI_CHAT_RESPONSE_INVALID_READ_MESSAGE;
  }
  if(response_chat == TREINAI_CHAT_RESPONSE_ERROR_ALOCATED){
    return TREINAI_CHAT_RESPONSE_ERROR_ALOCATED_MESSAGE;
  }
  return TREINAI_CHAT_RESPONSE_GENERIC_ERROR;
}


