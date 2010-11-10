/*-----------------------------------------------------------------------------+    
Copyright (c) 2008-2009: Joachim Faulhaber
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#ifndef LIBS_ICL_TEST_TEST_ICL_itv_quantifier_shared_h_JOFA_090119__
#define LIBS_ICL_TEST_TEST_ICL_itv_quantifier_shared_h_JOFA_090119__


//------------------------------------------------------------------------------
// Monoid EAN
//------------------------------------------------------------------------------
template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_monoid_plus_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_MONOID_INSTANCE_WRT(plus) (map_a, map_b, map_c, val_pair, map_pair);
    CHECK_MONOID_INSTANCE_WRT(pipe) (map_a, map_b, map_c, val_pair, map_pair);
}


template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_monoid_et_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_MONOID_INSTANCE_WRT(et)   (map_a, map_b, map_c, val_pair, map_pair);
    CHECK_MONOID_INSTANCE_WRT(caret)(map_a, map_b, map_c, val_pair, map_pair);
}

//------------------------------------------------------------------------------
// Abelian monoid EANC
//------------------------------------------------------------------------------

template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_abelian_monoid_plus_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_ABELIAN_MONOID_INSTANCE_WRT(plus) (map_a, map_b, map_c, val_pair, map_pair);
    CHECK_ABELIAN_MONOID_INSTANCE_WRT(pipe) (map_a, map_b, map_c, val_pair, map_pair);
}


template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_abelian_monoid_et_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_ABELIAN_MONOID_INSTANCE_WRT(et)   (map_a, map_b, map_c, val_pair, map_pair);
    CHECK_ABELIAN_MONOID_INSTANCE_WRT(caret)(map_a, map_b, map_c, val_pair, map_pair);
}


//------------------------------------------------------------------------------
// Abelian partial invertive monoid 
//------------------------------------------------------------------------------
template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_partial_invertive_monoid_plus_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_PARTIAL_INVERTIVE_MONOID_INSTANCE_WRT(plus) (map_a, map_b, map_c, val_pair, map_pair);
    CHECK_PARTIAL_INVERTIVE_MONOID_INSTANCE_WRT(pipe) (map_a, map_b, map_c, val_pair, map_pair);
}

//------------------------------------------------------------------------------
// Abelian partial invertive monoid with protonic equality for inversion
//------------------------------------------------------------------------------
template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_partial_invertive_monoid_plus_prot_inv_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_ABELIAN_MONOID_INSTANCE_WRT(plus)(map_a, map_b, map_c, val_pair, map_pair);
    CHECK_ABELIAN_MONOID_INSTANCE_WRT(pipe)(map_a, map_b, map_c, val_pair, map_pair);

    CHECK_PARTIAL_INVERTIVE_MONOID_INSTANCE_WRT_EQUAL(plus)(is_distinct_equal, map_a, map_b, map_c, val_pair, map_pair);
    CHECK_PARTIAL_INVERTIVE_MONOID_INSTANCE_WRT_EQUAL(pipe)(is_distinct_equal, map_a, map_b, map_c, val_pair, map_pair);
}


//------------------------------------------------------------------------------
// Abelian group EANIC
//------------------------------------------------------------------------------
template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_abelian_group_plus_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_ABELIAN_GROUP_INSTANCE_WRT(plus) (map_a, map_b, map_c, val_pair, map_pair);
    CHECK_ABELIAN_GROUP_INSTANCE_WRT(pipe) (map_a, map_b, map_c, val_pair, map_pair);
}

//------------------------------------------------------------------------------
// (0 - x) + x =p= 0  |  
//------------------------------------------------------------------------------
template <class T, class U, class Trt,
          template<class T, class U,
                   class Traits = Trt,
                   ICL_COMPARE Compare = ICL_COMPARE_INSTANCE(std::less, U),
                   ICL_COMBINE Combine = ICL_COMBINE_INSTANCE(icl::inplace_plus, U),
                   ICL_SECTION Section = ICL_SECTION_INSTANCE(icl::inter_section, U),
                   ICL_INTERVAL(ICL_COMPARE)  Interval = ICL_INTERVAL_INSTANCE(ICL_INTERVAL_DEFAULT, T, Compare),
                   ICL_ALLOC   Alloc   = std::allocator
                  >class IntervalMap
          >
void itv_quantifier_check_abelian_group_plus_prot_inv_4_bicremental_types()
{
    typedef IntervalMap<T,U,Trt> IntervalMapT;

    IntervalMapT map_a, map_b, map_c;
    map_a.add(IDv(3,6,1)).add(IIv(5,7,1));
    map_b.add(CDv(1,3,1)).add(IDv(8,9,1));
    map_c.add(IDv(0,9,2)).add(IIv(3,6,1)).add(IDv(5,7,1));

    typename IntervalMapT::interval_mapping_type val_pair = IDv(6,9,1);
    mapping_pair<T,U> map_pair = K_v(5,1);

    CHECK_ABELIAN_MONOID_INSTANCE_WRT(plus) (map_a, map_b, map_c, val_pair, map_pair);
    CHECK_ABELIAN_MONOID_INSTANCE_WRT(pipe) (map_a, map_b, map_c, val_pair, map_pair);

    CHECK_ABELIAN_GROUP_INSTANCE_WRT_EQUAL(plus) (is_distinct_equal, map_a, map_b, map_c, val_pair, map_pair);
    CHECK_ABELIAN_GROUP_INSTANCE_WRT_EQUAL(pipe) (is_distinct_equal, map_a, map_b, map_c, val_pair, map_pair);
}

#endif // LIBS_ICL_TEST_TEST_ICL_itv_quantifier_shared_h_JOFA_090119__
