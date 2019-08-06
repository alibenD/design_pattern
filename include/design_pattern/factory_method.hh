#ifndef __FACTORY_METHOD_HH__
#define __FACTORY_METHOD_HH__
/**-----------------------------------------------
  * @Copyright (C) 2019 All rights reserved.
  * @date: 2019
  * @file: factory_method.hh
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @create_date: 2019-08-06 09:57:00
  * @last_modified_date: 2019-08-06 12:15:48
  * @brief: TODO
  * @details: TODO
  *-----------------------------------------------*/

// Header include

// Declaration
/*
 * Avoid to using new
 *
 */

class ISplitter;

class SplitterFactory
{
  public:
    virtual ISplitter* CreateSplitter() = 0;
    virtual ~SplitterFactory() = default;
};

class ISplitter
{
  public:
    virtual void split() = 0;
    virtual ~ISplitter() = default;
};

class BinarySplitter : public ISplitter
{
  public:
    virtual void split() override;
    virtual ~BinarySplitter(){};
};

class TxtSplitter : public ISplitter
{
  public:
    virtual void split() override;
    virtual ~TxtSplitter() = default;
};

class VideoSplitter : public ISplitter
{
  public:
    virtual void split() override;
    virtual ~VideoSplitter() = default;
};

class BinarySplitterFactory : public SplitterFactory
{
  public:
    virtual ISplitter* CreateSplitter() override;
    virtual ~BinarySplitterFactory() = default;
};

class TxtSplitterFactory : public SplitterFactory
{
  public:
    virtual ISplitter* CreateSplitter() override;
    virtual ~TxtSplitterFactory() = default;
};

class VideoSplitterFactory : public SplitterFactory
{
  public:
    virtual ISplitter* CreateSplitter() override;
    virtual ~VideoSplitterFactory() = default;
};

//==================================

class ExamplerFactory
{
  public:
    ExamplerFactory(SplitterFactory* factory){this->ptr_factory_ = factory;};
    void Run();

  private:
    SplitterFactory* ptr_factory_;
};
#endif // __FACTORY_METHOD_HH__
