///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "WiFi.h"
#include "WiFiMock.hxx"
#include "Utils.h"
#include "LoggerMock.h"
#include "gmock/gmock.h"
#include "WiFiFixture.hxx"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// FUNCTIONS ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_F (WiFiFixture, VerifyThatYouHaveSwitchedToStationMode)
{
    LOGW (MODULE, "VerifyThatYouHaveSwitchedToStationMode");

    EXPECT_CALL (WiFiMock, startStation ()).Times (ONE);
    EXPECT_CALL (WiFiMock, startApp     ()).Times (ZERO);

    WiFiMock.SwitchMode (WiFi<class WiFiMock>::EMode::eStation);
}

TEST_F (WiFiFixture, VerifyThatYouHaveSwitchedToAppMode)
{
    LOGW (MODULE, "VerifyThatYouHaveSwitchedToAppMode");

    EXPECT_CALL (WiFiMock, startStation ()).Times (ZERO);
    EXPECT_CALL (WiFiMock, startApp     ()).Times (ONE);

    WiFiMock.SwitchMode (WiFi<class WiFiMock>::EMode::eApp);
}

TEST_F (WiFiFixture, VerifyThatEventStartWorked)
{
    LOGW (MODULE, "VerifyThatEventStartWorked");

    WiFiMock.OnEvent (WiFi<class WiFiMock>::EEvents::eStart);
    
    EXPECT_EQ (WiFiMock.IsOnline () , false);
    EXPECT_EQ (WiFiMock.Mode.Started, true);
}

TEST_F (WiFiFixture, VerifyThatEventStopWorked)
{
    LOGW (MODULE, "VerifyThatEventStopWorked");

    WiFiMock.OnEvent (WiFi<class WiFiMock>::EEvents::eStop);

    EXPECT_EQ (WiFiMock.IsOnline () , false);
    EXPECT_EQ (WiFiMock.Mode.Started, false);
}

TEST_F (WiFiFixture, VerifyThatEventGotIpWorked)
{
    LOGW (MODULE, "VerifyThatEventGotIpWorked");

    WiFiMock.OnEvent (WiFi<class WiFiMock>::EEvents::eGotIp);

    EXPECT_EQ (WiFiMock.IsOnline (), true);
}

TEST_F (WiFiFixture, VerifyThatEventDisconnectedWorked)
{
    LOGW (MODULE, "VerifyThatEventDisconnectedWorked");

    WiFiMock.OnEvent (WiFi<class WiFiMock>::EEvents::eDisconnected);

    EXPECT_EQ (WiFiMock.IsOnline (), false);
}

TEST_F (WiFiFixture, VerifyThatEventDisabledWorked)
{
    LOGW (MODULE, "VerifyThatEventDisabledWorked");

    WiFiMock.OnEvent (WiFi<class WiFiMock>::EEvents::eDisabled);

    EXPECT_EQ (WiFiMock.IsOnline (), false);
}

TEST_F (WiFiFixture, VerifyThatEventLostIpWorked)
{
    LOGW (MODULE, "VerifyThatEventLostIpWorked");

    WiFiMock.OnEvent (WiFi<class WiFiMock>::EEvents::eLostIp);

    EXPECT_EQ (WiFiMock.IsOnline (), false);
}
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////