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

#define BREAKING_RADIUS_LIMIT 20
#define BREAKING_DEATH_RADIUS_LIMIT 6

#define PEACEFUL_UNION_FACTOR 5

class Kid : public Rigid_body {
protected:
    int id;
    Kid_type type;
    int anger, charisma, courage;
    bool dead;
    Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage);

public:
    virtual void hit(Kid *other_kid, Kid *pKid) {};
    int get_id() const { return id; }
    Kid_type get_type(){ return type; }
    int get_anger(){ return anger; }
    int get_charisma(){ return charisma; }
    int get_courage(){ return courage; }
    void set_id(int _id){ id = _id; }

    static bool compare_kid_id(const Kid *lhs, const Kid *rhs);
    void print_kid_condition();
    bool is_dead(){ return dead; };
    void die(){ dead = true; }
    bool does_break(Kid *old_other_kid);

    Kid* copy_yourself(){ return new Kid(*this); };

    void check_death_conditions();
    void unite_peaceful_friends(int num_of_friends);
};


#endif //INC_05_AP_TA_KID_H
