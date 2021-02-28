///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "WiFi.h"
#include "Utils.h"
#include "WiFiHw.h"
#include "LoggerHw.h"
#include "gmock/gmock.h"
#include "WiFiFixture.hxx"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// FUNCTIONS ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_F (WiFiFixture, VerifyThatYouHaveSwitchedToStationMode)
{
    LOGW (MODULE, "VerifyThatYouHaveSwitchedToStationMode");

    EXPECT_CALL (WiFiHw, startStation ()).Times (ONE);
    EXPECT_CALL (WiFiHw, startApp     ()).Times (ZERO);

    WiFiHw.SwitchMode (WiFi<class WiFiHw>::EMode::eStation);
}

TEST_F (WiFiFixture, VerifyThatYouHaveSwitchedToAppMode)
{
    LOGW (MODULE, "VerifyThatYouHaveSwitchedToAppMode");

    EXPECT_CALL (WiFiHw, startStation ()).Times (ZERO);
    EXPECT_CALL (WiFiHw, startApp     ()).Times (ONE);

    WiFiHw.SwitchMode (WiFi<class WiFiHw>::EMode::eApp);
}

TEST_F (WiFiFixture, VerifyThatEventStartWorked)
{
    LOGW (MODULE, "VerifyThatEventStartWorked");

    WiFiHw.OnEvent (WiFi<class WiFiHw>::EEvents::eStart);
    
    EXPECT_EQ (WiFiHw.IsOnline () , false);
    EXPECT_EQ (WiFiHw.Mode.Started, true);
}

TEST_F (WiFiFixture, VerifyThatEventStopWorked)
{
    LOGW (MODULE, "VerifyThatEventStopWorked");

    WiFiHw.OnEvent (WiFi<class WiFiHw>::EEvents::eStop);

    EXPECT_EQ (WiFiHw.IsOnline () , false);
    EXPECT_EQ (WiFiHw.Mode.Started, false);
}

TEST_F (WiFiFixture, VerifyThatEventGotIpWorked)
{
    LOGW (MODULE, "VerifyThatEventGotIpWorked");

    WiFiHw.OnEvent (WiFi<class WiFiHw>::EEvents::eGotIp);

    EXPECT_EQ (WiFiHw.IsOnline (), true);
}

TEST_F (WiFiFixture, VerifyThatEventDisconnectedWorked)
{
    LOGW (MODULE, "VerifyThatEventDisconnectedWorked");

    WiFiHw.OnEvent (WiFi<class WiFiHw>::EEvents::eDisconnected);

    EXPECT_EQ (WiFiHw.IsOnline (), false);
}

TEST_F (WiFiFixture, VerifyThatEventDisabledWorked)
{
    LOGW (MODULE, "VerifyThatEventDisabledWorked");

    WiFiHw.OnEvent (WiFi<class WiFiHw>::EEvents::eDisabled);

    EXPECT_EQ (WiFiHw.IsOnline (), false);
}

TEST_F (WiFiFixture, VerifyThatEventLostIpWorked)
{
    LOGW (MODULE, "VerifyThatEventLostIpWorked");

    WiFiHw.OnEvent (WiFi<class WiFiHw>::EEvents::eLostIp);

    EXPECT_EQ (WiFiHw.IsOnline (), false);
}
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////