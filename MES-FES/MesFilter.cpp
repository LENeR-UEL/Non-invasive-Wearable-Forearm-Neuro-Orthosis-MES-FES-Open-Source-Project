#include "MesFilter.h"

MesFilter::MesFilter() {
    this->high_pass = new Filter(this->f1, this->sampling_time, this->order, this->typeHP);
    this->low_pass = new Filter(this->f2, this->sampling_time, this->order);
}

MesFilter::~MesFilter() {
    delete this->high_pass;
    delete this->low_pass;
}