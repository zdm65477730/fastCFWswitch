#pragma once
#include <tesla.hpp>
#include "payload.h"

namespace fastCFWSwitcher {

    enum class PayloadType { 
        UNKOWN = 1, 
        HEKATE = 2 
    };

    class PayloadHandler{

        public:
            PayloadHandler(tsl::elm::OverlayFrame* frame) : frame(frame){
            }
            ~PayloadHandler(){}
            void rebootToPayload(fastCFWSwitcher::Payload* payload);

        private:
            void setError(std::string errorString);
            void do_iram_dram_copy(void *buf, uintptr_t iram_addr, size_t size, int option);
            void copy_to_iram(uintptr_t iram_addr, void *buf, size_t size);
            void copy_from_iram(void *buf, uintptr_t iram_addr, size_t size) ;
            void clear_iram(void);
            bool loadPayload(fastCFWSwitcher::Payload* payload);
            void applyPayloadArgs(fastCFWSwitcher::Payload* payload);
            PayloadType getBinPayloadType(fastCFWSwitcher::Payload* payload);
            tsl::elm::OverlayFrame* frame;
    };
}