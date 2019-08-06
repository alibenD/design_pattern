#ifndef __BUIDLER_HH__
#define __BUIDLER_HH__
/**-----------------------------------------------
  * @Copyright (C) 2019 All rights reserved.
  * @date: 2019
  * @file: buidler.hh
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @create_date: 2019-08-06 14:19:28
  * @last_modified_date: 2019-08-06 15:41:09
  * @brief: TODO
  * @details: TODO
  *-----------------------------------------------*/

// Header include

// Declaration

class House
{
  public:
    virtual ~House() = default;
    virtual void Part1() = 0;
    virtual void Part2() = 0;
    virtual void Part3() = 0;
    virtual void Part4() = 0;
    virtual void Part5() = 0;
};

class StoneHouse : public House
{
  public:
    virtual ~StoneHouse() = default;
    virtual void Part1() override;
    virtual void Part2() override;
    virtual void Part3() override;
    virtual void Part4() override;
    virtual void Part5() override;
};

class IronHouse : public House
{
  public:
    virtual ~IronHouse() = default;
    virtual void Part1() override;
    virtual void Part2() override;
    virtual void Part3() override;
    virtual void Part4() override;
    virtual void Part5() override;
};

class HouseBuilder
{
  public:
    House* GetHouse(){return ptr_house_;};
    void Init();
    virtual ~HouseBuilder() = default;

  protected:
    House* ptr_house_;
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual void BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};

class StoneHouseBuilder : public HouseBuilder
{
  public:
    StoneHouseBuilder() { ptr_house_ = new StoneHouse(); };
    virtual ~StoneHouseBuilder() = default;
  protected:
    virtual void BuildPart1() override;
    virtual void BuildPart2() override;
    virtual void BuildPart3() override;
    virtual void BuildPart4() override;
    virtual void BuildPart5() override;
};

class IronHouseBuilder : public HouseBuilder
{
  public:
    IronHouseBuilder() { ptr_house_ = new IronHouse(); };
    virtual ~IronHouseBuilder() = default;
  protected:
    virtual void BuildPart1() override;
    virtual void BuildPart2() override;
    virtual void BuildPart3() override;
    virtual void BuildPart4() override;
    virtual void BuildPart5() override;
};

class HouseDirector
{
  public:
    HouseDirector(HouseBuilder* house_builder)
    {
      this->ptr_house_builder_ = house_builder;
    }
    House* Construct();
  private:
    HouseBuilder* ptr_house_builder_;
};
#endif // __BUIDLER_HH__
