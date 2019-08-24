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
    Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage);
    bool dead;
    void break_to_six(Kid* old_other_kid, Kid* real_other_kid);
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
    bool is_dead(){ return dead; };
    bool does_break(Kid *old_other_kid);
    void die(){ dead = true; }
    Kid* copy_yourself(){ return new Kid(*this); };
    void set_id(int _id){ id = _id; }
    void check_death();
    void unite_peaceful_friends(int num_of_friends){ courage += num_of_friends * PEACEFUL_UNION_FACTOR; }
};


#endif //INC_05_AP_TA_KID_H
