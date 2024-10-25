#pragma once

/* Generated with cbindgen:0.26.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>
#include "slint_enums_internal.h"
namespace slint::cbindgen_private { struct ParsedSVG{}; struct HTMLImage{}; using namespace vtable; namespace types{ struct NineSliceImage{}; } }

namespace slint {
namespace cbindgen_private {
namespace types {

/// This enum describes the origin to use when rendering a borrowed OpenGL texture.
/// Use this with [`BorrowedOpenGLTextureBuilder::origin`].
enum class BorrowedOpenGLTextureOrigin : uint8_t {
    /// The top-left of the texture is the top-left of the texture drawn on the screen.
    TopLeft,
    /// The bottom-left of the texture is the top-left of the texture draw on the screen,
    /// flipping it vertically.
    BottomLeft,
};

/// The pixel format of a StaticTexture
enum class PixelFormat : uint8_t {
    /// red, green, blue. 24bits.
    Rgb,
    /// Red, green, blue, alpha. 32bits.
    Rgba,
    /// Red, green, blue, alpha. 32bits. The color are premultiplied by alpha
    RgbaPremultiplied,
    /// Alpha map. 8bits. Each pixel is an alpha value. The color is specified separately.
    AlphaMap,
};

/// Represent a nine-slice image with the base image and the 4 borders
struct NineSliceImage;

/// A struct that provides a path as a string as well as the last modification
/// time of the file it points to.
struct CachedPath {
    SharedString path;
    /// SystemTime since UNIX_EPOC as secs
    uint64_t last_modified;

    bool operator==(const CachedPath& other) const {
        return path == other.path &&
               last_modified == other.last_modified;
    }
    bool operator!=(const CachedPath& other) const {
        return path != other.path ||
               last_modified != other.last_modified;
    }
};

/// ImageCacheKey encapsulates the different ways of indexing images in the
/// cache of decoded images.
union ImageCacheKey {
    enum class Tag : uint8_t {
        /// This variant indicates that no image cache key can be created for the image.
        /// For example this is the case for programmatically created images.
        Invalid = 0,
        /// The image is identified by its path on the file system and the last modification time stamp.
        Path = 1,
#if defined(SLINT_TARGET_WASM)
        /// The image is identified by a URL.
        URL = 2,
#endif
        /// The image is identified by the static address of its encoded data.
        EmbeddedData = 3,
    };

    struct Path_Body {
        Tag tag;
        CachedPath _0;

        bool operator==(const Path_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const Path_Body& other) const {
            return _0 != other._0;
        }
    };

#if defined(SLINT_TARGET_WASM)
    struct URL_Body {
        Tag tag;
        SharedString _0;

        bool operator==(const URL_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const URL_Body& other) const {
            return _0 != other._0;
        }
    };
#endif

    struct EmbeddedData_Body {
        Tag tag;
        uintptr_t _0;

        bool operator==(const EmbeddedData_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const EmbeddedData_Body& other) const {
            return _0 != other._0;
        }
    };

    struct {
        Tag tag;
    };
    Path_Body path;
#if defined(SLINT_TARGET_WASM)
    URL_Body url;
#endif
    EmbeddedData_Body embedded_data;

    static ImageCacheKey Invalid() {
        ImageCacheKey result;
        result.tag = Tag::Invalid;
        return result;
    }

    bool IsInvalid() const {
        return tag == Tag::Invalid;
    }

    static ImageCacheKey Path(const CachedPath &_0) {
        ImageCacheKey result;
        ::new (&result.path._0) (CachedPath)(_0);
        result.tag = Tag::Path;
        return result;
    }

    bool IsPath() const {
        return tag == Tag::Path;
    }

#if defined(SLINT_TARGET_WASM)
    static ImageCacheKey URL(const SharedString &_0) {
        ImageCacheKey result;
        ::new (&result.url._0) (SharedString)(_0);
        result.tag = Tag::URL;
        return result;
    }

    bool IsURL() const {
        return tag == Tag::URL;
    }
#endif

    static ImageCacheKey EmbeddedData(const uintptr_t &_0) {
        ImageCacheKey result;
        ::new (&result.embedded_data._0) (uintptr_t)(_0);
        result.tag = Tag::EmbeddedData;
        return result;
    }

    bool IsEmbeddedData() const {
        return tag == Tag::EmbeddedData;
    }

    bool operator==(const ImageCacheKey& other) const {
        if (tag != other.tag) {
            return false;
        }
        switch (tag) {
            case Tag::Path: return path == other.path;
#if defined(SLINT_TARGET_WASM)
            case Tag::URL: return url == other.url;
#endif
            case Tag::EmbeddedData: return embedded_data == other.embedded_data;
            default: break;
        }
        return true;
    }

    bool operator!=(const ImageCacheKey& other) const {
        return !(*this == other);
    }

    private:
    ImageCacheKey() {

    }
    public:


    ~ImageCacheKey() {
        switch (tag) {
            case Tag::Path: path.~Path_Body(); break;
#if defined(SLINT_TARGET_WASM)
            case Tag::URL: url.~URL_Body(); break;
#endif
            case Tag::EmbeddedData: embedded_data.~EmbeddedData_Body(); break;
            default: break;
        }
    }

    ImageCacheKey(const ImageCacheKey& other)
     : tag(other.tag) {
        switch (tag) {
            case Tag::Path: ::new (&path) (Path_Body)(other.path); break;
#if defined(SLINT_TARGET_WASM)
            case Tag::URL: ::new (&url) (URL_Body)(other.url); break;
#endif
            case Tag::EmbeddedData: ::new (&embedded_data) (EmbeddedData_Body)(other.embedded_data); break;
            default: break;
        }
    }
    ImageCacheKey& operator=(const ImageCacheKey& other) {
        if (this != &other) {
            this->~ImageCacheKey();
            new (this) ImageCacheKey(other);
        }
        return *this;
    }
};

/// SharedPixelBuffer is a container for storing image data as pixels. It is
/// internally reference counted and cheap to clone.
///
/// You can construct a new empty shared pixel buffer with [`SharedPixelBuffer::new`],
/// or you can clone it from an existing contiguous buffer that you might already have, using
/// [`SharedPixelBuffer::clone_from_slice`].
///
/// See the documentation for [`Image`] for examples how to use this type to integrate
/// Slint with external rendering functions.
template<typename Pixel>
struct SharedPixelBuffer {
    uint32_t width;
    uint32_t height;
    SharedVector<Pixel> data;

    bool operator==(const SharedPixelBuffer& other) const {
        return width == other.width &&
               height == other.height &&
               data == other.data;
    }
    bool operator!=(const SharedPixelBuffer& other) const {
        return width != other.width ||
               height != other.height ||
               data != other.data;
    }
};

/// SharedImageBuffer is a container for images that are stored in CPU accessible memory.
///
/// The SharedImageBuffer's variants represent the different common formats for encoding
/// images in pixels.
/// TODO: Make this non_exhaustive before making the type public!
struct SharedImageBuffer {
    enum class Tag {
        /// This variant holds the data for an image where each pixel has three color channels (red, green,
        /// and blue) and each channel is encoded as unsigned byte.
        RGB8,
        /// This variant holds the data for an image where each pixel has four color channels (red, green,
        /// blue and alpha) and each channel is encoded as unsigned byte.
        RGBA8,
        /// This variant holds the data for an image where each pixel has four color channels (red, green,
        /// blue and alpha) and each channel is encoded as unsigned byte. In contrast to [`Self::RGBA8`],
        /// this variant assumes that the alpha channel is also already multiplied to each red, green and blue
        /// component of each pixel.
        /// Only construct this format if you know that your pixels are encoded this way. It is more efficient
        /// for rendering.
        RGBA8Premultiplied,
    };

    struct RGB8_Body {
        SharedPixelBuffer<Rgb8Pixel> _0;

        bool operator==(const RGB8_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const RGB8_Body& other) const {
            return _0 != other._0;
        }
    };

    struct RGBA8_Body {
        SharedPixelBuffer<Rgba8Pixel> _0;

        bool operator==(const RGBA8_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const RGBA8_Body& other) const {
            return _0 != other._0;
        }
    };

    struct RGBA8Premultiplied_Body {
        SharedPixelBuffer<Rgba8Pixel> _0;

        bool operator==(const RGBA8Premultiplied_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const RGBA8Premultiplied_Body& other) const {
            return _0 != other._0;
        }
    };

    Tag tag;
    union {
        RGB8_Body rgb8;
        RGBA8_Body rgba8;
        RGBA8Premultiplied_Body rgba8_premultiplied;
    };

    static SharedImageBuffer RGB8(const SharedPixelBuffer<Rgb8Pixel> &_0) {
        SharedImageBuffer result;
        ::new (&result.rgb8._0) (SharedPixelBuffer<Rgb8Pixel>)(_0);
        result.tag = Tag::RGB8;
        return result;
    }

    bool IsRGB8() const {
        return tag == Tag::RGB8;
    }

    static SharedImageBuffer RGBA8(const SharedPixelBuffer<Rgba8Pixel> &_0) {
        SharedImageBuffer result;
        ::new (&result.rgba8._0) (SharedPixelBuffer<Rgba8Pixel>)(_0);
        result.tag = Tag::RGBA8;
        return result;
    }

    bool IsRGBA8() const {
        return tag == Tag::RGBA8;
    }

    static SharedImageBuffer RGBA8Premultiplied(const SharedPixelBuffer<Rgba8Pixel> &_0) {
        SharedImageBuffer result;
        ::new (&result.rgba8_premultiplied._0) (SharedPixelBuffer<Rgba8Pixel>)(_0);
        result.tag = Tag::RGBA8Premultiplied;
        return result;
    }

    bool IsRGBA8Premultiplied() const {
        return tag == Tag::RGBA8Premultiplied;
    }

    bool operator==(const SharedImageBuffer& other) const {
        if (tag != other.tag) {
            return false;
        }
        switch (tag) {
            case Tag::RGB8: return rgb8 == other.rgb8;
            case Tag::RGBA8: return rgba8 == other.rgba8;
            case Tag::RGBA8Premultiplied: return rgba8_premultiplied == other.rgba8_premultiplied;

        }
        return true;
    }

    bool operator!=(const SharedImageBuffer& other) const {
        return !(*this == other);
    }

    private:
    SharedImageBuffer() {

    }
    public:


    ~SharedImageBuffer() {
        switch (tag) {
            case Tag::RGB8: rgb8.~RGB8_Body(); break;
            case Tag::RGBA8: rgba8.~RGBA8_Body(); break;
            case Tag::RGBA8Premultiplied: rgba8_premultiplied.~RGBA8Premultiplied_Body(); break;

        }
    }

    SharedImageBuffer(const SharedImageBuffer& other)
     : tag(other.tag) {
        switch (tag) {
            case Tag::RGB8: ::new (&rgb8) (RGB8_Body)(other.rgb8); break;
            case Tag::RGBA8: ::new (&rgba8) (RGBA8_Body)(other.rgba8); break;
            case Tag::RGBA8Premultiplied: ::new (&rgba8_premultiplied) (RGBA8Premultiplied_Body)(other.rgba8_premultiplied); break;

        }
    }
    SharedImageBuffer& operator=(const SharedImageBuffer& other) {
        if (this != &other) {
            this->~SharedImageBuffer();
            new (this) SharedImageBuffer(other);
        }
        return *this;
    }
};

/// 2D Size in integer coordinates
using IntSize = Size2D<uint32_t>;

struct OpaqueImageVTable {
    Layout (*drop_in_place)(VRefMut<OpaqueImageVTable>);
    void (*dealloc)(const OpaqueImageVTable*, uint8_t *ptr, Layout layout);
    /// Returns the image size
    IntSize (*size)(VRef<OpaqueImageVTable>);
    /// Returns a cache key
    ImageCacheKey (*cache_key)(VRef<OpaqueImageVTable>);

    bool operator==(const OpaqueImageVTable& other) const {
        return drop_in_place == other.drop_in_place &&
               dealloc == other.dealloc &&
               size == other.size &&
               cache_key == other.cache_key;
    }
    bool operator!=(const OpaqueImageVTable& other) const {
        return drop_in_place != other.drop_in_place ||
               dealloc != other.dealloc ||
               size != other.size ||
               cache_key != other.cache_key;
    }
};

/// Expand IntRect so that cbindgen can see it. ( is in fact euclid::default::Rect<i32>)
struct IntRect {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;

    bool operator==(const IntRect& other) const {
        return x == other.x &&
               y == other.y &&
               width == other.width &&
               height == other.height;
    }
    bool operator!=(const IntRect& other) const {
        return x != other.x ||
               y != other.y ||
               width != other.width ||
               height != other.height;
    }
};

/// Some raw pixel data which is typically stored in the binary
struct StaticTexture {
    /// The position and size of the texture within the image
    IntRect rect;
    /// The pixel format of this texture
    PixelFormat format;
    /// The color, for the alpha map ones
    Color color;
    /// index in the data array
    uintptr_t index;

    bool operator==(const StaticTexture& other) const {
        return rect == other.rect &&
               format == other.format &&
               color == other.color &&
               index == other.index;
    }
    bool operator!=(const StaticTexture& other) const {
        return rect != other.rect ||
               format != other.format ||
               color != other.color ||
               index != other.index;
    }
};

/// A texture is stored in read-only memory and may be composed of sub-textures.
struct StaticTextures {
    /// The total size of the image (this might not be the size of the full image
    /// as some transparent part are not part of any texture)
    IntSize size;
    /// The size of the image before the compiler applied any scaling
    IntSize original_size;
    /// The pixel data referenced by the textures
    Slice<uint8_t> data;
    /// The list of textures
    Slice<StaticTexture> textures;

    bool operator==(const StaticTextures& other) const {
        return size == other.size &&
               original_size == other.original_size &&
               data == other.data &&
               textures == other.textures;
    }
    bool operator!=(const StaticTextures& other) const {
        return size != other.size ||
               original_size != other.original_size ||
               data != other.data ||
               textures != other.textures;
    }
};

#if !defined(SLINT_TARGET_WASM)
/// This structure contains fields to identify and render an OpenGL texture that Slint borrows from the application code.
/// Use this to embed a native OpenGL texture into a Slint scene.
///
/// The ownership of the texture remains with the application. It is the application's responsibility to delete the texture
/// when it is not used anymore.
///
/// Note that only 2D RGBA textures are supported.
struct BorrowedOpenGLTexture {
    /// The id or name of the texture, as created by [`glGenTextures`](https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGenTextures.xhtml).
    uint32_t texture_id;
    /// The size of the texture in pixels.
    IntSize size;
    /// Origin of the texture when rendering.
    BorrowedOpenGLTextureOrigin origin;

    bool operator==(const BorrowedOpenGLTexture& other) const {
        return texture_id == other.texture_id &&
               size == other.size &&
               origin == other.origin;
    }
    bool operator!=(const BorrowedOpenGLTexture& other) const {
        return texture_id != other.texture_id ||
               size != other.size ||
               origin != other.origin;
    }
};
#endif

/// A resource is a reference to binary data, for example images. They can be accessible on the file
/// system or embedded in the resulting binary. Or they might be URLs to a web server and a downloaded
/// is necessary before they can be used.
union ImageInner {
    enum class Tag : uint8_t {
        /// A resource that does not represent any data.
        ImageInner_None = 0,
        ImageInner_EmbeddedImage = 1,
        ImageInner_Svg = 2,
        ImageInner_StaticTextures = 3,
#if defined(SLINT_TARGET_WASM)
        ImageInner_HTMLImage = 4,
#endif
        ImageInner_BackendStorage = 5,
#if !defined(SLINT_TARGET_WASM)
        ImageInner_BorrowedOpenGLTexture = 6,
#endif
        ImageInner_NineSlice = 7,
    };

    struct ImageInner_EmbeddedImage_Body {
        Tag tag;
        ImageCacheKey cache_key;
        SharedImageBuffer buffer;

        bool operator==(const ImageInner_EmbeddedImage_Body& other) const {
            return cache_key == other.cache_key &&
                   buffer == other.buffer;
        }
        bool operator!=(const ImageInner_EmbeddedImage_Body& other) const {
            return cache_key != other.cache_key ||
                   buffer != other.buffer;
        }
    };

    struct ImageInner_Svg_Body {
        Tag tag;
        VRc<OpaqueImageVTable, ParsedSVG> _0;

        bool operator==(const ImageInner_Svg_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const ImageInner_Svg_Body& other) const {
            return _0 != other._0;
        }
    };

    struct ImageInner_StaticTextures_Body {
        Tag tag;
        const StaticTextures *_0;

        bool operator==(const ImageInner_StaticTextures_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const ImageInner_StaticTextures_Body& other) const {
            return _0 != other._0;
        }
    };

#if defined(SLINT_TARGET_WASM)
    struct ImageInner_HTMLImage_Body {
        Tag tag;
        VRc<OpaqueImageVTable, HTMLImage> _0;

        bool operator==(const ImageInner_HTMLImage_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const ImageInner_HTMLImage_Body& other) const {
            return _0 != other._0;
        }
    };
#endif

    struct ImageInner_BackendStorage_Body {
        Tag tag;
        VRc<OpaqueImageVTable> _0;

        bool operator==(const ImageInner_BackendStorage_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const ImageInner_BackendStorage_Body& other) const {
            return _0 != other._0;
        }
    };

#if !defined(SLINT_TARGET_WASM)
    struct ImageInner_BorrowedOpenGLTexture_Body {
        Tag tag;
        BorrowedOpenGLTexture _0;

        bool operator==(const ImageInner_BorrowedOpenGLTexture_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const ImageInner_BorrowedOpenGLTexture_Body& other) const {
            return _0 != other._0;
        }
    };
#endif

    struct ImageInner_NineSlice_Body {
        Tag tag;
        VRc<OpaqueImageVTable, NineSliceImage> _0;

        bool operator==(const ImageInner_NineSlice_Body& other) const {
            return _0 == other._0;
        }
        bool operator!=(const ImageInner_NineSlice_Body& other) const {
            return _0 != other._0;
        }
    };

    struct {
        Tag tag;
    };
    ImageInner_EmbeddedImage_Body embedded_image;
    ImageInner_Svg_Body svg;
    ImageInner_StaticTextures_Body static_textures;
#if defined(SLINT_TARGET_WASM)
    ImageInner_HTMLImage_Body html_image;
#endif
    ImageInner_BackendStorage_Body backend_storage;
#if !defined(SLINT_TARGET_WASM)
    ImageInner_BorrowedOpenGLTexture_Body borrowed_open_gl_texture;
#endif
    ImageInner_NineSlice_Body nine_slice;

    static ImageInner ImageInner_None() {
        ImageInner result;
        result.tag = Tag::ImageInner_None;
        return result;
    }

    bool IsImageInner_None() const {
        return tag == Tag::ImageInner_None;
    }

    static ImageInner ImageInner_EmbeddedImage(const ImageCacheKey &cache_key,
                                               const SharedImageBuffer &buffer) {
        ImageInner result;
        ::new (&result.embedded_image.cache_key) (ImageCacheKey)(cache_key);
        ::new (&result.embedded_image.buffer) (SharedImageBuffer)(buffer);
        result.tag = Tag::ImageInner_EmbeddedImage;
        return result;
    }

    bool IsImageInner_EmbeddedImage() const {
        return tag == Tag::ImageInner_EmbeddedImage;
    }

    static ImageInner ImageInner_Svg(const VRc<OpaqueImageVTable, ParsedSVG> &_0) {
        ImageInner result;
        ::new (&result.svg._0) (VRc<OpaqueImageVTable, ParsedSVG>)(_0);
        result.tag = Tag::ImageInner_Svg;
        return result;
    }

    bool IsImageInner_Svg() const {
        return tag == Tag::ImageInner_Svg;
    }

    static ImageInner ImageInner_StaticTextures(const StaticTextures *const &_0) {
        ImageInner result;
        ::new (&result.static_textures._0) (const StaticTextures*)(_0);
        result.tag = Tag::ImageInner_StaticTextures;
        return result;
    }

    bool IsImageInner_StaticTextures() const {
        return tag == Tag::ImageInner_StaticTextures;
    }

#if defined(SLINT_TARGET_WASM)
    static ImageInner ImageInner_HTMLImage(const VRc<OpaqueImageVTable, HTMLImage> &_0) {
        ImageInner result;
        ::new (&result.html_image._0) (VRc<OpaqueImageVTable, HTMLImage>)(_0);
        result.tag = Tag::ImageInner_HTMLImage;
        return result;
    }

    bool IsImageInner_HTMLImage() const {
        return tag == Tag::ImageInner_HTMLImage;
    }
#endif

    static ImageInner ImageInner_BackendStorage(const VRc<OpaqueImageVTable> &_0) {
        ImageInner result;
        ::new (&result.backend_storage._0) (VRc<OpaqueImageVTable>)(_0);
        result.tag = Tag::ImageInner_BackendStorage;
        return result;
    }

    bool IsImageInner_BackendStorage() const {
        return tag == Tag::ImageInner_BackendStorage;
    }

#if !defined(SLINT_TARGET_WASM)
    static ImageInner ImageInner_BorrowedOpenGLTexture(const BorrowedOpenGLTexture &_0) {
        ImageInner result;
        ::new (&result.borrowed_open_gl_texture._0) (BorrowedOpenGLTexture)(_0);
        result.tag = Tag::ImageInner_BorrowedOpenGLTexture;
        return result;
    }

    bool IsImageInner_BorrowedOpenGLTexture() const {
        return tag == Tag::ImageInner_BorrowedOpenGLTexture;
    }
#endif

    static ImageInner ImageInner_NineSlice(const VRc<OpaqueImageVTable, NineSliceImage> &_0) {
        ImageInner result;
        ::new (&result.nine_slice._0) (VRc<OpaqueImageVTable, NineSliceImage>)(_0);
        result.tag = Tag::ImageInner_NineSlice;
        return result;
    }

    bool IsImageInner_NineSlice() const {
        return tag == Tag::ImageInner_NineSlice;
    }

    bool operator==(const ImageInner& other) const {
        if (tag != other.tag) {
            return false;
        }
        switch (tag) {
            case Tag::ImageInner_EmbeddedImage: return embedded_image == other.embedded_image;
            case Tag::ImageInner_Svg: return svg == other.svg;
            case Tag::ImageInner_StaticTextures: return static_textures == other.static_textures;
#if defined(SLINT_TARGET_WASM)
            case Tag::ImageInner_HTMLImage: return html_image == other.html_image;
#endif
            case Tag::ImageInner_BackendStorage: return backend_storage == other.backend_storage;
#if !defined(SLINT_TARGET_WASM)
            case Tag::ImageInner_BorrowedOpenGLTexture: return borrowed_open_gl_texture == other.borrowed_open_gl_texture;
#endif
            case Tag::ImageInner_NineSlice: return nine_slice == other.nine_slice;
            default: break;
        }
        return true;
    }

    bool operator!=(const ImageInner& other) const {
        return !(*this == other);
    }

    private:
    ImageInner() {

    }
    public:


    ~ImageInner() {
        switch (tag) {
            case Tag::ImageInner_EmbeddedImage: embedded_image.~ImageInner_EmbeddedImage_Body(); break;
            case Tag::ImageInner_Svg: svg.~ImageInner_Svg_Body(); break;
            case Tag::ImageInner_StaticTextures: static_textures.~ImageInner_StaticTextures_Body(); break;
#if defined(SLINT_TARGET_WASM)
            case Tag::ImageInner_HTMLImage: html_image.~ImageInner_HTMLImage_Body(); break;
#endif
            case Tag::ImageInner_BackendStorage: backend_storage.~ImageInner_BackendStorage_Body(); break;
#if !defined(SLINT_TARGET_WASM)
            case Tag::ImageInner_BorrowedOpenGLTexture: borrowed_open_gl_texture.~ImageInner_BorrowedOpenGLTexture_Body(); break;
#endif
            case Tag::ImageInner_NineSlice: nine_slice.~ImageInner_NineSlice_Body(); break;
            default: break;
        }
    }

    ImageInner(const ImageInner& other)
     : tag(other.tag) {
        switch (tag) {
            case Tag::ImageInner_EmbeddedImage: ::new (&embedded_image) (ImageInner_EmbeddedImage_Body)(other.embedded_image); break;
            case Tag::ImageInner_Svg: ::new (&svg) (ImageInner_Svg_Body)(other.svg); break;
            case Tag::ImageInner_StaticTextures: ::new (&static_textures) (ImageInner_StaticTextures_Body)(other.static_textures); break;
#if defined(SLINT_TARGET_WASM)
            case Tag::ImageInner_HTMLImage: ::new (&html_image) (ImageInner_HTMLImage_Body)(other.html_image); break;
#endif
            case Tag::ImageInner_BackendStorage: ::new (&backend_storage) (ImageInner_BackendStorage_Body)(other.backend_storage); break;
#if !defined(SLINT_TARGET_WASM)
            case Tag::ImageInner_BorrowedOpenGLTexture: ::new (&borrowed_open_gl_texture) (ImageInner_BorrowedOpenGLTexture_Body)(other.borrowed_open_gl_texture); break;
#endif
            case Tag::ImageInner_NineSlice: ::new (&nine_slice) (ImageInner_NineSlice_Body)(other.nine_slice); break;
            default: break;
        }
    }
    ImageInner& operator=(const ImageInner& other) {
        if (this != &other) {
            this->~ImageInner();
            new (this) ImageInner(other);
        }
        return *this;
    }
};

/// An image type that can be displayed by the Image element. You can construct
/// Image objects from a path to an image file on disk, using [`Self::load_from_path`].
///
/// Another typical use-case is to render the image content with Rust code.
/// For this it's most efficient to create a new SharedPixelBuffer with the known dimensions
/// and pass the mutable slice to your rendering function. Afterwards you can create an
/// Image.
///
/// The following example creates a 320x200 RGB pixel buffer and calls an external
/// low_level_render() function to draw a shape into it. Finally the result is
/// stored in an Image with [`Self::from_rgb8()`]:
/// ```
/// # use i_slint_core::graphics::{SharedPixelBuffer, Image, Rgb8Pixel};
///
/// fn low_level_render(width: u32, height: u32, buffer: &mut [u8]) {
///     // render beautiful circle or other shapes here
/// }
///
/// let mut pixel_buffer = SharedPixelBuffer::<Rgb8Pixel>::new(320, 200);
///
/// low_level_render(pixel_buffer.width(), pixel_buffer.height(),
///                  pixel_buffer.make_mut_bytes());
///
/// let image = Image::from_rgb8(pixel_buffer);
/// ```
///
/// Another use-case is to import existing image data into Slint, by
/// creating a new Image through cloning of another image type.
///
/// The following example uses the popular [image crate](https://docs.rs/image/) to
/// load a `.png` file from disk, apply brightening filter on it and then import
/// it into an [`Image`]:
/// ```no_run
/// # use i_slint_core::graphics::{SharedPixelBuffer, Image, Rgba8Pixel};
/// let mut cat_image = image::open("cat.png").expect("Error loading cat image").into_rgba8();
///
/// image::imageops::colorops::brighten_in_place(&mut cat_image, 20);
///
/// let buffer = SharedPixelBuffer::<Rgba8Pixel>::clone_from_slice(
///     cat_image.as_raw(),
///     cat_image.width(),
///     cat_image.height(),
/// );
/// let image = Image::from_rgba8(buffer);
/// ```
///
/// A popular software (CPU) rendering library in Rust is tiny-skia. The following example shows
/// how to use tiny-skia to render into a [`SharedPixelBuffer`]:
/// ```
/// # use i_slint_core::graphics::{SharedPixelBuffer, Image, Rgba8Pixel};
/// let mut pixel_buffer = SharedPixelBuffer::<Rgba8Pixel>::new(640, 480);
/// let width = pixel_buffer.width();
/// let height = pixel_buffer.height();
/// let mut pixmap = tiny_skia::PixmapMut::from_bytes(
///     pixel_buffer.make_mut_bytes(), width, height
/// ).unwrap();
/// pixmap.fill(tiny_skia::Color::TRANSPARENT);
///
/// let circle = tiny_skia::PathBuilder::from_circle(320., 240., 150.).unwrap();
///
/// let mut paint = tiny_skia::Paint::default();
/// paint.shader = tiny_skia::LinearGradient::new(
///     tiny_skia::Point::from_xy(100.0, 100.0),
///     tiny_skia::Point::from_xy(400.0, 400.0),
///     vec![
///         tiny_skia::GradientStop::new(0.0, tiny_skia::Color::from_rgba8(50, 127, 150, 200)),
///         tiny_skia::GradientStop::new(1.0, tiny_skia::Color::from_rgba8(220, 140, 75, 180)),
///     ],
///     tiny_skia::SpreadMode::Pad,
///     tiny_skia::Transform::identity(),
/// ).unwrap();
///
/// pixmap.fill_path(&circle, &paint, tiny_skia::FillRule::Winding, Default::default(), None);
///
/// let image = Image::from_rgba8_premultiplied(pixel_buffer);
/// ```
///
/// ### Sending Image to a thread
///
/// `Image` is not [`Send`], because it uses internal cache that are local to the Slint thread.
/// If you want to create image data in a thread and send that to slint, construct the
/// [`SharedPixelBuffer`] in a thread, and send that to Slint's UI thread.
///
/// ```rust,no_run
/// # use i_slint_core::graphics::{SharedPixelBuffer, Image, Rgba8Pixel};
/// std::thread::spawn(move || {
///     let mut pixel_buffer = SharedPixelBuffer::<Rgba8Pixel>::new(640, 480);
///     // ... fill the pixel_buffer with data as shown in the previous example ...
///     slint::invoke_from_event_loop(move || {
///         // this will run in the Slint's UI thread
///         let image = Image::from_rgba8_premultiplied(pixel_buffer);
///         // ... use the image, eg:
///         // my_ui_handle.upgrade().unwrap().set_image(image);
///     });
/// });
/// ```
using Image = ImageInner;

/// 2D Size
using Size = Size2D<float>;

extern "C" {

void slint_image_load_from_path(const SharedString *path, Image *image);

void slint_image_load_from_embedded_data(Slice<uint8_t> data, Slice<uint8_t> format, Image *image);

IntSize slint_image_size(const Image *image);

const SharedString *slint_image_path(const Image *image);

void slint_image_from_embedded_textures(const StaticTextures *textures, Image *image);

bool slint_image_compare_equal(const Image *image1, const Image *image2);

/// Call [`Image::set_nine_slice_edges`]
void slint_image_set_nine_slice_edges(Image *image,
                                      uint16_t top,
                                      uint16_t right,
                                      uint16_t bottom,
                                      uint16_t left);

} // extern "C"

} // namespace types
} // namespace cbindgen_private
} // namespace slint
