#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::StreamReader
    @ingroup IO
    @brief base class for stream readers
 
    Stream readers provide a way to read structured/formatted data 
    from Stream objects. To use, create a StreamReader and attach
    an already open Stream object. The Stream object must have been
    opened with a readable OpenMode.
*/
#include "Core/RefCounted.h"

namespace Oryol {

class Stream;
    
class StreamReader : public RefCounted {
    OryolClassDecl(StreamReader);
public:
    /// default constructor
    StreamReader();
    /// construct with Stream object (Stream object must be open)
    StreamReader(const Ptr<Stream>& stream);
    /// destructor
    virtual ~StreamReader();
    
    /// attach stream object (must be open, replaces previous object)
    virtual void AttachStream(const Ptr<Stream>& stream);
    /// detach stream object
    virtual void DetachStream();
    /// get currently attached stream object
    const Ptr<Stream>& GetStream() const;
    
protected:
    Ptr<Stream> stream;
};

} // namespace Oryol