#ifndef GLLANDINGPAGE_H
#define GLLANDINGPAGE_H


class GLLandingPage
{
    public:
        GLLandingPage();
        virtual ~GLLandingPage();

            void activate();
            void deactivate();
            bool isActive();

    protected:

    private:
         bool active;
};

#endif // GLLANDINGPAGE_H
