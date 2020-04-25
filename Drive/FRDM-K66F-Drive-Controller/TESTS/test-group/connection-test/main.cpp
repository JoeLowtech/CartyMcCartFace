#include "mbed.h"
#include "utest/utest.h"
#include "unity/unity.h"
#include "greentea-client/test_env.h"

#include "CommunicationInterface.h"

using namespace utest::v1;

// mbed test -t ARM -m auto -v -n tests-test-group-connection-test

static void ethernet_tcp_test(void) {
    /* test content here */
    CommunicationInterface server;
    TEST_ASSERT_EQUAL(0, server.start());
    TEST_ASSERT_EQUAL_STRING("192.168.178.24", server.get_client_ip());
    
    // Overall bytes received
    TEST_ASSERT_EQUAL(8, server.recv());
    // Decoded test message
    driveMessage* receivedMessage = server.get_message();
    TEST_ASSERT_EQUAL_INT32(1500,receivedMessage->steering);
    TEST_ASSERT_EQUAL_INT32(0.5,receivedMessage->power);
}

utest::v1::status_t greentea_setup(const size_t number_of_cases) {
    // Here, we specify the timeout (60s) and the host test (a built-in host test or the name of our Python file)
    GREENTEA_SETUP(60, "default_auto");

    return greentea_test_setup_handler(number_of_cases);
}

// List of test cases in this file
Case cases[] = {
    Case("ethernet tcp test", ethernet_tcp_test)
};

Specification specification(greentea_setup, cases);

int main() {
    return !Harness::run(specification);
}