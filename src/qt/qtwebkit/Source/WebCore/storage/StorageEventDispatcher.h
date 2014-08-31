/*
 * Copyright (C) 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef StorageEventDispatcher_h
#define StorageEventDispatcher_h

#include <wtf/Forward.h>
#include <wtf/Vector.h>

namespace WebCore {

class Frame;
class Page;
class PageGroup;
class SecurityOrigin;

class StorageEventDispatcher {
public:
    static void dispatchSessionStorageEvents(const String& key, const String& oldValue, const String& newValue, SecurityOrigin*, Frame* sourceFrame);
    static void dispatchLocalStorageEvents(const String& key, const String& oldValue, const String& newValue, SecurityOrigin*, Frame* sourceFrame);

    static void dispatchSessionStorageEventsToFrames(Page&, const Vector<RefPtr<Frame> >& frames, const String& key, const String& oldValue, const String& newValue, const String& url, SecurityOrigin*);
    static void dispatchLocalStorageEventsToFrames(PageGroup&, const Vector<RefPtr<Frame> >& frames, const String& key, const String& oldValue, const String& newValue, const String& url, SecurityOrigin*);
private:
    // Do not instantiate.
    StorageEventDispatcher();
};

} // namespace WebCore

#endif // StorageEventDispatcher_h