//
// Created by Mohsen on 8/21/2019.
//

#ifndef INC_05_AP_TA_KID_H
#define INC_05_AP_TA_KID_H

#include "Kid_type.h"
#include "../Rigid_body/Rigid_body.h"

#define ANGRY "Angry"
#define PEACEFUL "Peaceful"
#define COWARD "Coward"

#define DEATH_ANGER_LIMIT 100
#define DEATH_RADIUS_LIMIT 0

class Kid : public Rigid_body {
protected:
    int id;
    Kid_type type;
    int anger, charisma, courage;
    Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage);
    bool dead;
    Kid* old_kid_copy;
    void die(){ dead = true; }
    void check_death();
public:
    virtual void hit(Kid *other_kid, Kid *pKid) {};
    int get_id() const { return id; }
    Kid_type get_type(){ return type; }
    int get_anger(){ return anger; }
    int get_charisma(){ return charisma; }
    int get_courage(){ return courage; }
    static bool compare_kid_id(const Kid *lhs, const Kid *rhs){
        return (lhs->get_id() < rhs->get_id());
    }
    void print_kid_condition();
    void make_a_copy();
    bool is_dead(){ return dead; };
};


#endif //INC_05_AP_TA_KID_H
