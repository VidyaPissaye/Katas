/* 
 * File:   GildedRose.h
 * Author: Vidya
 *
 * Created on January 24, 2013, 1:45 AM
 */

#ifndef GILDEDROSE_H
#define	GILDEDROSE_H

#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
};



#endif	/* GILDEDROSE_H */

