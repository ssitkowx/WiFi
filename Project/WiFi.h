#pragma once 

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "Utils.h"
#include <string>
#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// MACROS/DEFINITIONS ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define SSID_LEN     THIRTY_TWO_BYTES
#define PASSWORD_LEN SIXTY_FOUR_BYTES
#define MAC_LEN      SIX_BYTES

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// VARIABLES ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <class DERIVED_TYPE>
class WiFi
{
    friend DERIVED_TYPE;
    DERIVED_TYPE & derivedType = static_cast <DERIVED_TYPE &> (*this);

    public:
        enum class EMode
        {
            eStation,
            eApp,
        };

        enum class EEvents
        {
            eStart,
            eStop,
            eDisconnected,
            eConnected,
            eGotIp,
            eLostIp,
            eEnabled,
            eDisabled,
            eApStart,
            eApDisconnected,
            eApConnected,
            eApEnabled,
            eApDisabled
        };

        struct Modes
        {
            bool Started         = false;
            bool StaConnected    = false;
            bool SoftApConnected = false;
        };

        static inline Modes Mode;

        WiFi () = default;

        static  bool  IsOnline  (void) { return WiFi::Mode.StaConnected; }
        void          Reconnect (void) { derivedType.Reconnect (); }

    protected:
        struct Config
        {
            struct NetworkParams
            {
                std::string Ipv4;
                std::string Mask;
                std::string Gateway;
                std::string Ipv6;
            } NetParams;
            
            struct EModes
            {
                uint8_t Ssid     [SSID_LEN];
                uint8_t Password [PASSWORD_LEN];
            } Station = {{ZERO}, {ZERO}}, SoftAp = {{ZERO}, {ZERO}};
        } settings;

        void startStation (void) { derivedType.startStation (); }
        void startApp     (void) { derivedType.startApp     (); }
        void switchMode   (EMode v_eMode)
        {
            switch (v_eMode)
            {
                case EMode::eStation:
                {
                    startStation ();
                    break;
                }
                case EMode::eApp:
                {
                    startApp ();
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        static void onEvent (EEvents v_event)
        {
            const uint16_t event = static_cast <uint16_t> (v_event);
            switch (event)
            {
                case static_cast<uint16_t>(EEvents::eStart):
                {
                    Mode.Started = true;
                    Mode.StaConnected = false;
                    break;
                }
                case static_cast<uint16_t>(EEvents::eStop):
                {
                    Mode.Started = false;
                    Mode.StaConnected = false;
                    break;
                }
                case static_cast<uint16_t>(EEvents::eDisconnected):
                case static_cast<uint16_t>(EEvents::eDisabled):
                case static_cast<uint16_t>(EEvents::eLostIp):
                {
                    Mode.StaConnected = false;
                    break;
                }
                case static_cast<uint16_t>(EEvents::eConnected):
                {
                    break;
                }
                case static_cast<uint16_t>(EEvents::eGotIp):
                {
                    Mode.StaConnected = true;
                    break;
                }
            }
        }

    private:
        ~WiFi () = default;
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
