/*
 * File:   newtestclass.h
 * Author: Vidya
 *
 * Created on Jan 24, 2013, 2:21:15 AM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testGildedRose);
    CPPUNIT_TEST(testUpdateQuality);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testGildedRose();
    void testUpdateQuality();

};

#endif	/* NEWTESTCLASS_H */

